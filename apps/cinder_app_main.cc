
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "my_app.h"


using cinder::app::App;
using cinder::app::RendererGl;


namespace flappygameapp {

    const int kSamples = 8;
    const int kWidth = 1600;
    const int kHeight = 1600;

    void SetUp(App::Settings* settings) {
        settings->setWindowSize(kWidth, kHeight);
        settings->setTitle("Flappy game");
    }

}

CINDER_APP(flappygameapp::FlappyGame,
           RendererGl(RendererGl::Options().msaa(flappygameapp::kSamples)),
           flappygameapp::SetUp)