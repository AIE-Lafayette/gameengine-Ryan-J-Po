#version 440 core

out vec4 FragColor;
in vec2 fragTexCoord;
uniform sampler2D sampleTexture;
uniform vec2 offset;

void main()
{
	FragColor = texture(sampleTexture, fragTexCoord + offset);

	if (FragColor.a < 0.1)
	{
	discard;
	}
}