void team_choosing() {
    std::string team = "";
    std::string position = "";

    while (true) {
        if (controller_1.buttonL1.pressing()) {
            brain.screen.draw_image_from_file("red_1_confirmed.png", 0, 0);
            while (controller_1.buttonL1.pressing()) {
                wait(5, msec);
            }
            return "red_1";
        } 
        else if (controller_1.buttonL2.pressing()) {
            brain.screen.draw_image_from_file("red_2_confirmed.png", 0, 0);
            while (controller_1.buttonL2.pressing()) {
                wait(5, msec);
            }
            return "red_2";
        } 
        else if (controller_1.buttonR1.pressing()) {
            brain.screen.draw_image_from_file("blue_1_confirmed.png", 0, 0);
            while (controller_1.buttonR1.pressing()) {
                wait(5, msec);
            }
            return "blue_1";
        } 
        else if (controller_1.buttonR2.pressing()) {
            brain.screen.draw_image_from_file("blue_2_confirmed.png", 0, 0);
            while (controller_1.buttonR2.pressing()) {
                wait(5, msec);
            }
            return "blue_2";
        }

        if (brain.screen.pressing() && 8 <= brain.screen.y_position() && brain.screen.y_position() <= 26) {
            // Team choosing
            if (139 <= brain.screen.x_position() && brain.screen.x_position() <= 240) {
                // Red
                team = "red";
                brain.screen.draw_image_from_file("red_begin.png", 0, 0);
                position = "";
            } 
            else if (249 <= brain.screen.x_position() && brain.screen.x_position() <= 351) {
                // Blue
                team = "blue";
                brain.screen.draw_image_from_file("blue_begin.png", 0, 0);
                position = "";
            } 
            else if (358 <= brain.screen.x_position() && brain.screen.x_position() <= 461) {
                // Skill
                team = "skill";
                brain.screen.draw_image_from_file("skill_begin.png", 0, 0);
                position = "";
            }
        } 
        else if (brain.screen.pressing() && 19 <= brain.screen.x_position() && brain.screen.x_position() <= 138 && !team.empty()) {
            // Position selection
            if (brain.screen.y_position() > 52 && brain.screen.y_position() < 73) {
                if (team == "red") {
                    brain.screen.draw_image_from_file("red_1.png", 0, 0);
                } 
                else if (team == "blue") {
                    brain.screen.draw_image_from_file("blue_1.png", 0, 0);
                } 
                else if (team == "skill") {
                    brain.screen.draw_image_from_file("skill_confirmed.png", 0, 0);
                    return "skill";
                }
                position = "1";
            } 
            else if (brain.screen.y_position() >= 85 && brain.screen.y_position() <= 107) {
                if (team == "red") {
                    brain.screen.draw_image_from_file("red_2.png", 0, 0);
                } 
                else if (team == "blue") {
                    brain.screen.draw_image_from_file("blue_2.png", 0, 0);
                }
                position = "2";
            } 
            else if (brain.screen.y_position() >= 120 && brain.screen.y_position() <= 142) {
                if (team == "red") {
                    if (position == "1") {
                        brain.screen.draw_image_from_file("red_1_confirmed.png", 0, 0);
                    } 
                    else if (position == "2") {
                        brain.screen.draw_image_from_file("red_2_confirmed.png", 0, 0);
                    }
                } 
                else if (team == "blue") {
                    if (position == "1") {
                        brain.screen.draw_image_from_file("blue_1_confirmed.png", 0, 0);
                    } 
                    else if (position == "2") {
                        brain.screen.draw_image_from_file("blue_2_confirmed.png", 0, 0);
                    }
                }
                return team + "_" + position;
            }

            while (brain.screen.pressing()) {
                wait(5, msec);
            }
        }
        wait(5, msec);
    }
}
