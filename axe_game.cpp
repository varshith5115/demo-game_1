#include "raylib.h"
int main()
{
    int width{800};
    int height{450};
    InitWindow(width,height,"varshith");

    int circle_x{100};
    int circle_y{200};
    int circle_rad{25};
    //circle edges
    int l_circle_x{circle_x-circle_rad};
    int r_circle_x{circle_x+circle_rad};
    int u_circle_y{circle_y-circle_rad};
    int b_circle_y{circle_y+circle_rad};
    

    int axe_x{250};
    int axe_y{0};
    int axe_len{50};
    int direction{10};
    //axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x+axe_len};
    int u_axe_y{axe_y};
    int b_axe_y{axe_x+axe_len};

    bool collision_with_axe=(b_axe_y>=u_circle_y)&&
                            (u_axe_y<=b_circle_y)&&
                            (r_axe_x>=l_circle_x)&&
                            (l_axe_x<=r_circle_x);

    int axe1_x{450};
    int axe1_y{450};
    int axe1_len{50};
    int direction1{10};
    //axe edges
    int l_axe1_x{axe_x};
    int r_axe1_x{axe_x+axe_len};
    int u_axe1_y{axe_y};
    int b_axe1_y{axe_x+axe_len};

    bool collision_with_axe1=(b_axe1_y>=u_circle_y)&&
                            (u_axe1_y<=b_circle_y)&&
                            (r_axe1_x>=l_circle_x)&&
                            (l_axe1_x<=r_circle_x);
    SetTargetFPS(60);
    while (WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(BLUE);

        if(collision_with_axe || collision_with_axe1)
        {
            DrawText("Game Over!",350,200,20,RED);
        }
        else
        {
            //logic begins

            //update edges
            l_circle_x=circle_x-circle_rad;
            r_circle_x=circle_x+circle_rad;
            b_circle_y=circle_y+circle_rad;
            u_circle_y=circle_y-circle_rad;
            l_axe_x=axe_x;
            r_axe_x=axe_x+axe_len;
            b_axe_y=axe_y+axe_len;
            u_axe_y=axe_y;
            l_axe1_x=axe1_x;
            r_axe1_x=axe1_x+axe1_len;
            b_axe1_y=axe1_y+axe1_len;
            u_axe1_y=axe1_y;

            //update collision with axe
             collision_with_axe=(b_axe_y>=u_circle_y)&&
                            (u_axe_y<=b_circle_y)&&
                            (r_axe_x>=l_circle_x)&&
                            (l_axe_x<=r_circle_x);
            collision_with_axe1=(b_axe1_y>=u_circle_y)&&
                            (u_axe1_y<=b_circle_y)&&
                            (r_axe1_x>=l_circle_x)&&
                            (l_axe1_x<=r_circle_x);


            DrawCircle(circle_x,circle_y,circle_rad,BLACK);
            DrawRectangle(axe_x,axe_y,axe_len,axe_len,WHITE);
            DrawRectangle(axe1_x,axe1_y,axe1_len,axe1_len,WHITE);

            axe_y+=direction;
            axe1_y+=direction1;
            if (axe_y>height || axe_y<0)
            {
                direction=-direction;
            }

             if (axe1_y>height || axe1_y<0)
            {
                direction1=-direction1;
            }
            

            if(IsKeyDown(KEY_D) && circle_x<width)
            {
                circle_x+=10;
            }

            if(IsKeyDown(KEY_A) && circle_x>0)
            {
                circle_x-=10;
            }
            //logic ends
        }
        
        
        EndDrawing();
    }
    


}