#include <math.h>

#include "OpenGLShapeRenderer.h"


#include "openGLSource/VertexArray.h"
#include "openGLSource/VertexBuffer.h"
#include "openGLSource/VertexBufferLayout.h"


OpenGLShapeRenderer::OpenGLShapeRenderer() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGLShapeRenderer::addShape(const Circle& circle)
{
	float x = (float)circle.getX();
	float y = (float)circle.getY();
	float radius = (float)circle.getRadius();
	float sqrt3 = sqrt(3);

	circleVertexBuffer.push_back(x - radius * sqrt3); //Vertex
	circleVertexBuffer.push_back(y - radius);

	circleVertexBuffer.push_back(x);//Center
	circleVertexBuffer.push_back(y);

	circleVertexBuffer.push_back(radius); //Radius

	circleVertexBuffer.push_back(1.0);	//Color
	circleVertexBuffer.push_back(0.0);
	circleVertexBuffer.push_back(0.0);
	circleVertexBuffer.push_back(1.0);


	circleVertexBuffer.push_back(x + radius * sqrt3);
	circleVertexBuffer.push_back(y - radius);

	circleVertexBuffer.push_back(x);//Center
	circleVertexBuffer.push_back(y);

	circleVertexBuffer.push_back(radius); //Radius

	circleVertexBuffer.push_back(0.0);	//Color
	circleVertexBuffer.push_back(1.0);
	circleVertexBuffer.push_back(0.0);
	circleVertexBuffer.push_back(1.0);

	circleVertexBuffer.push_back(x);
	circleVertexBuffer.push_back(y + radius * 2);

	circleVertexBuffer.push_back(x);//Center
	circleVertexBuffer.push_back(y);

	circleVertexBuffer.push_back(radius); //Radius

	circleVertexBuffer.push_back(0.0);	//Color
	circleVertexBuffer.push_back(0.0);
	circleVertexBuffer.push_back(1.0);
	circleVertexBuffer.push_back(1.0);




	circleIndexBuffer.push_back(circleCount * 3 + 0);
	circleIndexBuffer.push_back(circleCount * 3 + 1);
	circleIndexBuffer.push_back(circleCount * 3 + 2);

	

	circleCount++;
}

void OpenGLShapeRenderer::addShape(const Rectangle& rectangle)
{
	float x = (float)rectangle.getX();
	float y = (float)rectangle.getY();
	float width = (float)rectangle.getWidth();
	float height = (float)rectangle.getHeight();

	rectangleVertexBuffer.push_back(x - width / 2);
	rectangleVertexBuffer.push_back(y - height / 2);

	rectangleVertexBuffer.push_back(x + width / 2);
	rectangleVertexBuffer.push_back(y - height / 2);

	rectangleVertexBuffer.push_back(x + width / 2);
	rectangleVertexBuffer.push_back(y + height / 2);

	rectangleVertexBuffer.push_back(x - width / 2);
	rectangleVertexBuffer.push_back(y + height / 2);


	rectangleIndexBuffer.push_back(rectangleCount * 4 + 0);
	rectangleIndexBuffer.push_back(rectangleCount * 4 + 1);
	rectangleIndexBuffer.push_back(rectangleCount * 4 + 2);

	rectangleIndexBuffer.push_back(rectangleCount * 4 + 2);
	rectangleIndexBuffer.push_back(rectangleCount * 4 + 3);
	rectangleIndexBuffer.push_back(rectangleCount * 4 + 0);

	rectangleCount++;
}

void OpenGLShapeRenderer::render()
{
	Renderer renderer;

	

	VertexArray va_rectangle;
	VertexBuffer vb_rectangle(rectangleVertexBuffer.data(), rectangleVertexBuffer.size() * sizeof(float));

	VertexBufferLayout layout_rectangle;
	layout_rectangle.Push<float>(2);
	va_rectangle.AddBuffer(vb_rectangle, layout_rectangle);

	IndexBuffer ib_rectangle{ rectangleIndexBuffer.data(), static_cast<unsigned int>(rectangleIndexBuffer.size())};

	Shader shader_rectangle("res/shaders/Basic.shader");
	shader_rectangle.Bind();
	shader_rectangle.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);


	VertexArray va_circle;
	VertexBuffer vb_circle(circleVertexBuffer.data(), circleVertexBuffer.size() * sizeof(float));
	VertexBufferLayout layout_circle;
	layout_circle.Push<float>(2);
	layout_circle.Push<float>(2);
	layout_circle.Push<float>(1);
	layout_circle.Push<float>(4);
	va_circle.AddBuffer(vb_circle, layout_circle);

	IndexBuffer ib_circle{ circleIndexBuffer.data(), static_cast<unsigned int>(circleIndexBuffer.size()) };

	Shader shader_circle("res/shaders/Circle.shader");
	shader_circle.Bind();


	renderer.Clear();
	renderer.Draw(va_rectangle, ib_rectangle, shader_rectangle);
	renderer.Draw(va_circle, ib_circle, shader_circle);


	rectangleVertexBuffer.clear();
	rectangleIndexBuffer.clear();
	circleVertexBuffer.clear();
	circleIndexBuffer.clear();

	rectangleCount = 0;
	circleCount = 0;

}
