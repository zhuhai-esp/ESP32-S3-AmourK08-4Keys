#ifndef __TFT_DEBUG_DRAW__
#define __TFT_DEBUG_DRAW__

#include "lgfx.h"
#include <Arduino.h>
#include <box2d/box2d.h>

extern LGFX_Sprite sprite;

class TFTDebugDraw : public b2Draw {

  void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount,
                   const b2Color &color) {}

  void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount,
                        const b2Color &color) {
    for (int i = 0; i < vertexCount; i++) {
      auto p1 = vertices[i];
      auto p2 = vertices[(i + 1) % vertexCount];
      sprite.drawLine(p1.x * 10, p1.y * 10, p2.x * 10, p2.y * 10, TFT_YELLOW);
    }
  }

  void DrawCircle(const b2Vec2 &center, float radius, const b2Color &color) {}

  void DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis,
                       const b2Color &color) {
    auto r = (int)round(radius * 10);
    sprite.drawCircle(center.x * 10, center.y * 10, r, TFT_PINK);
  }

  void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) {}

  void DrawTransform(const b2Transform &xf) {}

  void DrawPoint(const b2Vec2 &p, float size, const b2Color &color) {}
};

#endif