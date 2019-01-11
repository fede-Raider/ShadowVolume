# ShadowVolume
Shadow Volume technique implemented in C++ with OpenGL.

![ShadowVolume](https://image.ibb.co/maYiqH/Screenshot_2018_03_19_12_08_19.png)

Computer Graphics and 3D.

## Implementation
Depth fail:

1. Disable writes to the depth and color buffers.
2. Set the stencil operation to increment on depth fail (only count shadows behind the object) if front-face.
3. Set the stencil operation to decrement on depth fail if back-face.
4. Render the shadow volumes.
