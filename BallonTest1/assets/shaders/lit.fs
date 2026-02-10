precision mediump float;

varying vec3 vNormal;
varying vec3 vPosition;
varying vec2 vTexCoord;

uniform vec3 uLightPos;
uniform vec3 uLightColor;
uniform vec3 uAmbientColor;
uniform sampler2D uTexture;

void main() {
    vec3 normal = normalize(vNormal);
    vec3 lightDir = normalize(uLightPos - vPosition);
    
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = diff * uLightColor;
    
    vec3 ambient = uAmbientColor;
    
    vec4 textureColor = texture2D(uTexture, vTexCoord);
    vec3 result = (ambient + diffuse) * textureColor.rgb;
    
    gl_FragColor = vec4(result, textureColor.a);
}