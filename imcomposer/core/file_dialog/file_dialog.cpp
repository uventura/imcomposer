#include "imcomposer/core/file_dialog/file_dialog.h"
#include "imcomposer/utils/thread.h"

#include "third_party/portable_file_dialogs/portable_file_dialogs.h"
#include <thread>
#include <iostream>

ImComposer::Core::FileDialog::FileDialog() {
}

void ImComposer::Core::FileDialog::reset() {
    if(currentState_ == ImComposer::ThreadState::FINISHED
    || currentState_ == ImComposer::ThreadState::ABORTED) {
        currentState_ = ImComposer::ThreadState::NOT_RUNNING;
        (*dialogThread_.get()).join();
    }
}

void ImComposer::Core::FileDialog::openFile() {
    reset();

    if(currentState_ == ImComposer::ThreadState::NOT_RUNNING)
    {
        currentState_ = ImComposer::ThreadState::RUNNING;
        dialogThread_ = std::make_unique<std::thread>(&FileDialog::openFileAction, this);
    }
}

void ImComposer::Core::FileDialog::openFileAction() {
    auto openFileDialog = pfd::open_file("Open File", ".", {"*.json"});

    if(!openFileDialog.result().empty()) {
        openedFile_ = openFileDialog.result()[0];
        currentState_ = ImComposer::ThreadState::FINISHED;
        return;
    }

    currentState_ = ImComposer::ThreadState::ABORTED;    
}

