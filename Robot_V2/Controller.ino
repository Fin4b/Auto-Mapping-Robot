



void onConnectedController(ControllerPtr ctl) 
{
    myController = ctl;
}

void onDisconnectedController(ControllerPtr ctl)
{
    myController = nullptr;
}

void setupController() 
{
    BP32.setup(&onConnectedController, &onDisconnectedController);
}

void updateController() 
{
    BP32.update();
    if (myController && myController->isConnected()) 
    {
        if (myController->a()) currentMode = AUTO;  Serial.println("Auto mode");
        if (myController->x()) currentMode = MANUAL;  Serial.println("Manual mode");
        if (myController->y()) currentMode = NAVIGATE;  Serial.println("Navigate mode");
        if (myController->b()) stopMotors();  Serial.println("Emergency Stop");
    }
}