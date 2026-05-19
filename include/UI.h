#ifndef UI_H
#define UI_H

#include <string>

namespace UI {
    void curataEcran();
    void pauza();
    void afiseazaBannerStart();
    void afiseazaMeniu();
    void mesajSucces(const std::string& text);
    void mesajEroare(const std::string& text);
    void afiseazaTitlu(const std::string& titlu);
}

#endif
