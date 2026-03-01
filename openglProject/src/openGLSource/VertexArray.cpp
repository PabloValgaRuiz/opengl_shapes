#include "VertexArray.h"
#include "Renderer.h"
#include "VertexBufferLayout.h"
VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RendererID);
    //glBindVertexArray(m_RendererID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    Bind();

	vb.Bind();

    const auto& elements = layout.GetElements();

    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++) {
        const auto& element = elements[i];


        glEnableVertexAttribArray(i  /*index of the attribute*/); //Enable this to work

        glVertexAttribPointer(
            i   /*index of the attribute: this binds the attribute to the index i of the vertex array object (vao) that is bound*/,

            element.count,
            element.type,
            element.normalized,//false: we give a value from 0.0f to 1.0f, true : we give a value from 0 to 255
            layout.GetStride(),//in bytes
            (const void*)offset /*displacement of the attribute in bytes*/);

        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }

    
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_RendererID);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}
