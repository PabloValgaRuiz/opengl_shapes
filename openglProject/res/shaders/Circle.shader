#shader vertex
#version 450 core

in layout(location = 0) vec4 in_position;
in layout(location = 1) vec2 in_center;
in layout(location = 2) float in_radius;
in layout(location = 3) vec4 in_color;

out vec4 position;
out vec2 center;
out float radius;
out vec4 color;


void main()

{
    gl_Position = vec4(in_position);
    position = in_position;
    center = in_center;
    radius = in_radius;
    color = in_color;

}

#shader fragment
#version 450 core

in vec4 position;
in vec2 center;
in float radius;
in vec4 color;
out layout(location = 0) vec4 out_color;


void main()

{
    if ((position.x - center.x) * (position.x - center.x) + (position.y - center.y) * (position.y - center.y) < radius * radius)
        out_color = vec4(position.xyz + vec3(0.5,0.5,0.1), 1);

    else out_color = vec4(0,0,1, 0.04);

    //out_color = vec4(1, 1, 1, 1.0);
}