#!/bin/bash

IMAGE_NAME=my-ubuntu_24.04-env

# 현재 스크립트 기준으로 Git repo 루트 절대경로 계산
REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# 빌드 (REPO_ROOT 기준으로 docker 디렉토리 지정)
docker build -t $IMAGE_NAME "$REPO_ROOT/docker"

# 컨테이너 실행
docker run -it \
  -v "$REPO_ROOT":/home/user/algorithm-study \
  -w /home/user/algorithm-study \
  $IMAGE_NAME
