#shader vertex
#version 450 core

in layout(location = 0) vec3 in_position;

in layout(location = 1) vec3 in_normal;

uniform mat4 Model = mat4(1);

uniform mat4 View = mat4(1);

uniform mat4 Projection = mat4(1);

out VS_FS_INTERFACE{

    vec3 position;

    vec3 normal;

} vertex;

void main()

{

    mat4 MVP = Projection * View * Model;

    gl_Position = MVP * vec4(in_position, 1);

    vertex.position = (Model * vec4(in_position, 1)).xyz;

    vertex.normal = (Model * vec4(in_normal, 0)).xyz;

}

#shader fragment
#version 450 core


in VS_FS_INTERFACE{

    vec3 position;

    vec3 normal;

} vertex;

out layout(location = 0) vec4 out_color;

uniform vec2 u_Center;

void main()

{
    if ((vertex.position.x - u_Center.x) * (vertex.position.x - u_Center.x) + (vertex.position.y - u_Center.y) * (vertex.position.y - u_Center.y) < 1)
        out_color = vec4(1, 1, 1, 1);
    else out_color = vec4(0, 0, 0, 0);

}