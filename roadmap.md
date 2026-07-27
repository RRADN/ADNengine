# ADN Engine Roadmap

This roadmap is based on the current state of the codebase: the engine already boots an SDL3 window, runs a render loop, draws textures and screens, and has early input, entity, and collision systems in place.

## Current State

- SDL3 window, renderer, and event loop are wired in `src/main.cpp`.
- Basic rendering exists through `src/platform/rendering/renderManager.cpp` and `src/platform/rendering/textures/textureManager.cpp`.
- Input systems are present in `src/logic/input/`.
- Primitive entities and collision scaffolding already exist in `src/entities/primitive/` and `src/logic/systems/collisions/`.
- Asset generation is automated through `src/scripts/generator.py` and the CMake custom target.
- ImGui is vendored and linked, so debug tooling and editor-style overlays are available.

## Roadmap

### Phase 1: Stabilize the Core Loop

Goal: make the current runtime predictable and easier to extend.

- Move startup and shutdown flow into a dedicated application layer instead of keeping everything in `main.cpp`.
- Define a clean frame update order: input, events, simulation, rendering, present.
- Add explicit error handling for SDL initialization, renderer creation, and asset loading.
- Ensure resources are destroyed deterministically with RAII wrappers where possible.

### Phase 2: Complete the Foundation Systems

Goal: turn the existing scaffolding into reusable engine systems.

- Finish the input abstraction so key and action mapping is data-driven.
- Expand collision handling from basic checks into a reusable system with clear response rules.
- Add entity lifecycle management for creation, update, draw, and removal.
- Centralize configuration values for resolution, timing, and display behavior.

### Phase 3: Strengthen Rendering

Goal: make drawing more flexible for real gameplay scenes.

- Extend texture handling with caching, hot-reload-friendly structure, or clearer load states.
- Add sprite batching or at least render grouping to reduce repeated state changes.
- Introduce camera or world-to-screen separation.
- Add text rendering support in `src/platform/rendering/text/`.

### Phase 4: Build Gameplay Primitives

Goal: provide the minimum set of gameplay objects needed to make a game with the engine.

- Add reusable primitives such as ball, paddle, tile map, or other test gameplay objects.
- Add movement components or movement systems separate from collision code.
- Implement simple score, health, and state management systems.
- Define a scene or level concept so game logic is not hard-coded into the startup loop.

### Phase 5: Tooling and Developer Experience

Goal: make the project easier to maintain and debug.

- Add a small test or validation strategy for non-visual systems.
- Improve logging and on-screen debug output with ImGui.
- Document build requirements and runtime assumptions in the README.
- Keep generated assets and source assets clearly separated.

### Phase 6: Packaging and Cross-Platform Polish

Goal: prepare the engine for broader use.

- Review Linux and Windows dependency handling so both paths are consistent.
- Simplify asset copying and runtime deployment.
- Add release build settings and packaging notes.
- Verify debug sanitizers and release flags do not conflict.

## Suggested Milestones

1. A clean app wrapper around the current SDL bootstrap.
2. Reliable input, collision, and entity lifecycle behavior.
3. Stronger texture, camera, and text rendering support.
4. A small playable sample built on the engine.
5. Better debug tooling, documentation, and packaging.

## Notes

- The current project already has a useful vertical slice, so the next work should focus on structure and reliability rather than rewriting the engine.
- The fastest way to validate progress is to keep a small sample scene runnable at all times.