function toFullScreen(videoDom){

  if(videoDom.requestFullscreen){

    return videoDom.requestFullscreen();

  }else if(videoDom.webkitRequestFullScreen){

    return videoDom.webkitRequestFullScreen();

  }else if(videoDom.mozRequestFullScreen){

    return videoDom.mozRequestFullScreen();

  }else{

    return videoDom.msRequestFullscreen();

  }

}
function unFullScreen() {
    var de = document;
    if (de.exitFullscreen) {
        de.exitFullscreen();
    } else if (de.mozCancelFullScreen) {
        de.mozCancelFullScreen();
    } else if (de.webkitCancelFullScreen) {
        de.webkitCancelFullScreen();
    }
}