#include <a_samp>
#include <sscanf2>
#include <zcmd>

/*
    This include was made because everytime I was making some include or gamemode,
    I would end up making same functions or commands over and over again. Those are temporary functions 
    or commands which allows you to go to exact place of feature you are testing etc..

    As I'm trying to make this as minimal as possible, I will stick to zcmd for making commands first time in my life :D,
    as you will later exclude this as your dependency
    having sscanf and zcmd as only dependencies
*/

CMD:xgoto(playerid, params[])
{
    new Float: x, Float: y, Float: z, world, interior;
    if(sscanf(params, "fffI(-1)I(-1)", x, y, z, world, interior))
    {
        return SendClientMessage(playerid, -1, "USAGE: /xgoto [x][y][z][world][interior]");
    }
    SetPlayerPos(playerid, x, y, z);
    if(world != -1) SetPlayerVirtualWorld(playerid, world);
    if(interior != -1) SetPlayerInterior(playerid, interior);
    SendClientMessage(playerid, -1, "DEV: Successfully teleported");
    return 1;
}

CMD:vehicle(playerid, params[])
{
    new vehicle, color1, color2, delay;
    new Float: x, Float: y, Float: z, Float: a;
    if(sscanf(params, "dddd", vehicle, color1, color2, delay))
    {
        return SendClientMessage(playerid, -1, "USAGE: /vehicle [model (400-612)][color1][color2][respawn delay]");
    }
    if(vehicle < 400 || vehicle > 612)
    {
        return SendClientMessage(playerid, -1, "Invalid vehicleid");
    }
    if(delay < -1) 
    {
        return SendClientMessage(playerid, -1, "Minimum delay is -1");
    }
    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);
    CreateVehicle(vehicle, x+2, y, z+1, a, color1, color2, delay);
    SendClientMessage(playerid, -1, "DEV: Successfully created vehicle");
    return 1;
}

CMD:weapon(playerid, params[])
{
    new target, weapon, ammo;

    if(sscanf(params, "udd", target, weapon, ammo))
    {
        return SendClientMessage(playerid, -1, "USAGE: /weapon [player][weapon][ammo]");
    }
    if(!IsPlayerConnected(target))
    {
        return SendClientMessage(playerid, -1, "Not connected");
    }
    GivePlayerWeapon(target, weapon, ammo);
    SendClientMessage(playerid, -1, "Successfully given weapon.");
    SendClientMessage(target, -1, "You got weapon");
    return 1;
}

CMD:health(playerid, params[])
{
    new target, Float: health;
    if(sscanf(params, "uf", target, health))
    {
        return SendClientMessage(playerid, -1, "USAGE: /health [player][health]");
    }
    if(!IsPlayerConnected(target))
    {
        return SendClientMessage(playerid, -1, "Not connected");
    }
    SetPlayerHealth(playerid, health);
    SendClientMessage(playerid, -1, "Successfully set health.");
    SendClientMessage(target, -1, "You were set health");
    return 1;
}

CMD:fixveh(playerid, params[])
{
    if(!IsPlayerInAnyVehicle(playerid))
    {
        return SendClientMessage(playerid, -1, "You're not in any vehicle");
    }
    
    RepairVehicle(GetPlayerVehicleID(playerid));
    SendClientMessage(playerid, -1, "You repaired vehicle.");
    return 1;
}

CMD:port(playerid, params[])
{
    new option, target; //1 yourself to target 2 target to yourself
    new Float: x, Float: y, Float: z;
    if(sscanf(params, "ud", target, option))
    {
        SendClientMessage(playerid, -1, "USAGE: /port [target][option (1-2)]");
        return SendClientMessage(playerid, -1, "OPTIONS: 1 - Yourself to target 2 - Target to yourself");
    }
    if(!IsPlayerConnected(target))
    {
        return SendClientMessage(playerid, -1, "Not connected");
    }
    if(target == playerid)
    {
        return SendClientMessage(playerid, -1, "You can't be same as target");
    }
    if(option == 1)
    {
        GetPlayerPos(target, x, y, z);
        SetPlayerPos(playerid, x+0.3, y, z+0.1);
        SendClientMessage(playerid, -1, "You ported yourself");
    }
    else if(option == 2)
    {
        GetPlayerPos(playerid, x, y, z);
        SetPlayerPos(target, x+0.3, y, z+0.1);
        SendClientMessage(target, -1, "You have been ported");
    }
    else 
    {
        return SendClientMessage(playerid, -1, "Invalid option");
    }
    return 1;
}

CMD:world(playerid, params[])
{
    new string[46];
    format(string, sizeof(string), "Current virtualworld: %d", GetPlayerVirtualWorld(playerid));
    SendClientMessage(playerid, 0x92C0BEFF, string);
    return 1;
}

CMD:goxyz(playerid,params[])
{
    // /goxyz 0.0, 0.0, 3.0, 10, 0

    new Float: x, Float: y, Float: z, world, interior, string[72];
    if(sscanf(params, "s[72]", string)) return return SendClientMessage(playerid, -1, "USAGE: /goxyz [x,y,z,world,interior]"); 

    sscanf(string, "p<,>fffii", x, y, z, world, interior);

    SetPlayerPos(playerid, x, y, z);
    if(world != -1) SetPlayerVirtualWorld(playerid, world);
    if(interior != -1) SetPlayerInterior(playerid, interior);
    SendClientMessage(playerid, -1, "DEV: Successfully teleported");
    return 1;
}
