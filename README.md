# ShadowVolume
Shadow Volume technique implemented in C++ with OpenGL.

![ShadowVolume](https://image.ibb.co/maYiqH/Screenshot_2018_03_19_12_08_19.png)

Computer Graphics and 3D.

## Implementation
Depth fail:

1. Disable writes to the depth and color buffers.
2. Use front-face culling.
3. Set the stencil operation to increment on depth fail (only count shadows behind the object).
4. Render the shadow volumes.
5. Use back-face culling.
6. Set the stencil operation to decrement on depth fail.
7. Render the shadow volumes.
