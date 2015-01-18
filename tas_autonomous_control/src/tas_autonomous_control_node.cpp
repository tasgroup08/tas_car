#include "control/control.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "autonomous_control");
    control autonomous_control;
    double mult= 500;
    double multfak= 100;

    ros::Rate loop_rate(50);

    while(ros::ok())
    {
        if(autonomous_control.control_Mode.data==0)
        {
            ROS_INFO("Manually Control!");
        }
        else
        {
            if(autonomous_control.control_Brake.data==1)
            {
                autonomous_control.control_servo.x=1500;
                autonomous_control.control_servo.y=1500;
            }
            else
            {
                ROS_INFO("Automatic Control!");
                if(autonomous_control.cmd_linearVelocity>0)
                {	
			// Adapative velocity control
			// (unfortunatly no improvement was observed)
			//mult=800-abs(autonomous_control.cmd_steeringAngle-1500)*6;//5=899 (0.3 grad) 0=> 50=>500 
			//if(autonomous_control.cmd_steeringAngle<1450 || autonomous_control.cmd_steeringAngle>1550) 
			//{mult=5*multfak;}
			//else { autonomous_control.cmd_steeringAngle=autonomous_control.cmd_steeringAngle-(autonomous_control.cmd_steeringAngle-1500)/(abs(autonomous_control.cmd_steeringAngle-1500)+0.0000000000000001)}

			//instead of using constant servo command velocity use command velocity provided by move_base
			//multiplied by an appropriate value
			autonomous_control.control_servo.x=1500+autonomous_control.cmd_linearVelocity*mult;//1500+cmd_vel(usually around 0.1)*500
                        if(autonomous_control.control_servo.x>1590){ //maximum servo velocity
                    		autonomous_control.control_servo.x = 1590;}
                }
                else if(autonomous_control.cmd_linearVelocity<0)
                {
                    autonomous_control.control_servo.x = 1300;
                }
                else
                {
                    autonomous_control.control_servo.x = 1500;
                }

                autonomous_control.control_servo.y = autonomous_control.cmd_steeringAngle;
            }

            autonomous_control.control_servo_pub_.publish(autonomous_control.control_servo);

        }

        ros::spinOnce();
        loop_rate.sleep();

    }

    return 0;

}
