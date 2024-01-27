#ifndef IMCOMPOSER_UI_TOOLBAR
#define IMCOMPOSER_UI_TOOLBAR

namespace ImComposer
{
namespace Component
{
    class Toolbar
    {
        public:
            Toolbar();
            void begin();
            void setIconFont(ImFont* font);
        private:
            bool state_;
            ImFont* iconFont_;
    };
}
}

#endif
