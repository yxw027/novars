/*
 *
 * This file is a part of NovaRS.
 *     
 * NovaRS, the GNSS station controlling software.
 * Copyright (C) 2016  Mykhailo Lytvyn
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "daemonize.h"

#include <unistd.h>


int main(int argc, char** argv)
{
    // Create thread objects before demonizing

    BecomeDaemon(); // close all streams, detach from terminal, fork process
    SetupSignals(); // setup program to react on OS signals

    // Start threads here


    while(coughtShutdownSignal == 0 && coughtHupSignal == 0)
    {
        // main thread code here
        // ..
        usleep(100000);
    }

    // Stop threads here
    // ...

    // Remove PID file
    CleanUp();


    return 0;
}

