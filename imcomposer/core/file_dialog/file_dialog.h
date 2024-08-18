#include <future>
#include <memory>
#include <string>
#include <thread>

#include "imcomposer/utils/thread.h"

namespace ImComposer {
namespace Core {
class FileDialog {
 public:
  FileDialog();

  void openFile();
  inline std::string getValue() { return openedFile_; };

  inline bool isRunning() { return currentState_ == ThreadState::RUNNING; };
  inline bool isReady() { return currentState_ == ThreadState::FINISHED; };
  inline bool isAborted() { return currentState_ == ThreadState::ABORTED; }

  void reset();

 private:
  ImComposer::ThreadState currentState_{ThreadState::NOT_RUNNING};
  std::unique_ptr<std::thread> dialogThread_;
  std::string openedFile_;

  void openFileAction();
};
}  // namespace Core
}  // namespace ImComposer