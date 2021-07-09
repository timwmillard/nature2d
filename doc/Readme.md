# Natural 2D API Documentation

## core

### `vec2`
vec2 is type representing a 2D vector
- vec2() - creates a new vector
- vec2:add(v) — add vectors
- vec2:sub(v) — subtract vectors
- vec2:mult(n) — scale the vector with multiplication
- vec2:div(n) — scale the vector with division
- vec2:mag() — calculate the magnitude of a vector
- vec2:setMag(n) - set the magnitude of a vector
- vec2:normalize() — normalize the vector to a unit length of 1
- vec2:limit(n) — limit the magnitude of a vector
- vec2:heading() — the 2D heading of a vector expressed as an angle
- vec2:rotate(a) — rotate a 2D vector by an angle
- vec2:lerp(v) — linear interpolate to another vector
- vec2:dist(v) — the Euclidean distance between two vectors (considered as points)
- vec2:angleBetween(v) — find the angle between two vectors
- vec2:dot(v) — the dot product of two vectors
- vec2:cross(v) — the cross product of two vectors (only relevant in three dimensions)
- vec2.random() - make a random 2D vector

### `rect`
rect represents a 2D rectangle
- rect(x, y, w, h) - creates a new rectangle
- rect(start, end) - creates a new rectangle with a start `vec2` and end `vec2`
- rect:x — x postion (top right)
- rect:y — y position (top right)
- rect:width
- rect:height
- rect:area() - area of rectangle

- `matrix2`
- noise
- random
- map
- translate
- rotate

## nature.physics

- nature.physics.body
- nature.physics.world
- nature.physics.force
- nature.physics.collision
- nature.physics.applyForce(force)
- nature.physics.applyGravity(force)
- nature.physics.attrach(force)
- nature.physics.friction
- nature.physics.liquid
- nature.physics.pendulum
- nature.physics.oscillator
- nature.physics.spring
- nature.physics.particle
- nature.physics.particlesystem
- nature.physics.particlesystem:add(partical)

## nature.agents

## nature.cells

## nature.evolution

## nature.neuralnetworks

## nature.graphics

### nature.graphics.sprite

### nature.graphics.load()
### nature.keyboard.press()
### nature.graphics.update()
### nature.graphics.render()
