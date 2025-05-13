FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

# 필수 패키지 설치
RUN apt-get update && apt-get install -y \
    zsh \
    curl \
    git \
    vim \
    locales \
    sudo \
    python3 \
    python3-pip \
 && apt-get clean

# locale 설정
RUN locale-gen en_US.UTF-8
ENV LANG=en_US.UTF-8
ENV LANGUAGE=en_US:en
ENV LC_ALL=en_US.UTF-8

# 사용자 추가 (비root 사용자로)
RUN useradd -ms /bin/zsh user && echo "user ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
USER user
WORKDIR /home/user

# oh-my-zsh 설치
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended

# autosuggestions 플러그인 설치
RUN git clone https://github.com/zsh-users/zsh-autosuggestions.git ~/.oh-my-zsh/custom/plugins/zsh-autosuggestions

# syntax-highlighting 플러그인 설치
RUN git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting

# .zshrc 설정 업데이트
RUN sed -i 's/ZSH_THEME=".*"/ZSH_THEME="robbyrussell"/' ~/.zshrc && \
    sed -i 's/plugins=(git)/plugins=(git zsh-autosuggestions zsh-syntax-highlighting)/' ~/.zshrc

# 기본 셸을 zsh로 변경
RUN sudo chsh -s $(which zsh) user

# 시작 시 zsh 실행
CMD [ "zsh" ]
