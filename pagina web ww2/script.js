document.addEventListener("DOMContentLoaded", () => {
  // Carousel functionality
  const track = document.querySelector(".carousel-track")
  const slides = Array.from(document.querySelectorAll(".carousel-slide"))
  const nextButton = document.querySelector(".next-arrow")
  const prevButton = document.querySelector(".prev-arrow")
  const indicators = document.querySelectorAll(".indicator")

  let slideWidth = slides[0].getBoundingClientRect().width
  let slideIndex = 0
  const slidesToShow = window.innerWidth < 768 ? 1 : window.innerWidth < 992 ? 2 : 3
  const totalSlides = slides.length

  // Set slide positions
  const setSlidePosition = () => {
    slideWidth = slides[0].getBoundingClientRect().width
    slides.forEach((slide, index) => {
      slide.style.left = slideWidth * index + "px"
    })
  }

  // Update carousel
  const updateCarousel = () => {
    track.style.transform = `translateX(-${slideIndex * slideWidth * (window.innerWidth < 768 ? 1 : window.innerWidth < 992 ? 1 : 1)}px)`

    // Update indicators
    indicators.forEach((indicator, index) => {
      indicator.classList.toggle("active", index === slideIndex)
    })
  }

  // Initialize carousel
  setSlidePosition()

  // Event listeners for navigation
  nextButton.addEventListener("click", () => {
    if (slideIndex < totalSlides - slidesToShow) {
      slideIndex++
      updateCarousel()
    } else {
      // Loop back to first slide with animation
      track.style.transition = "none"
      slideIndex = 0
      setTimeout(() => {
        track.style.transition = "transform 0.5s ease"
        updateCarousel()
      }, 10)
    }
  })

  prevButton.addEventListener("click", () => {
    if (slideIndex > 0) {
      slideIndex--
      updateCarousel()
    } else {
      // Loop to last slide with animation
      track.style.transition = "none"
      slideIndex = totalSlides - slidesToShow
      setTimeout(() => {
        track.style.transition = "transform 0.5s ease"
        updateCarousel()
      }, 10)
    }
  })

  // Indicator clicks
  indicators.forEach((indicator, index) => {
    indicator.addEventListener("click", () => {
      slideIndex = index
      updateCarousel()
    })
  })

  // Window resize handler
  window.addEventListener("resize", () => {
    setSlidePosition()
    updateCarousel()
  })

  // Touch/swipe functionality for mobile
  let touchStartX = 0
  let touchEndX = 0

  track.addEventListener("touchstart", (e) => {
    touchStartX = e.changedTouches[0].screenX
  })

  track.addEventListener("touchend", (e) => {
    touchEndX = e.changedTouches[0].screenX
    handleSwipe()
  })

  const handleSwipe = () => {
    const swipeThreshold = 50
    if (touchEndX < touchStartX - swipeThreshold) {
      // Swipe left - next slide
      nextButton.click()
    } else if (touchEndX > touchStartX + swipeThreshold) {
      // Swipe right - previous slide
      prevButton.click()
    }
  }

  // Fullscreen section functionality
  const readMoreButtons = document.querySelectorAll(".read-more-btn")
  const fullscreenSections = document.getElementById("fullscreen-sections")
  const closeButtons = document.querySelectorAll(".close-section")

  readMoreButtons.forEach((button) => {
    button.addEventListener("click", (e) => {
      e.stopPropagation()
      const slide = button.closest(".carousel-slide")
      const sectionId = slide.dataset.section
      const section = document.getElementById(sectionId)

      // Show fullscreen container and specific section
      fullscreenSections.style.display = "block"
      document.body.style.overflow = "hidden"

      // Hide all sections first
      document.querySelectorAll(".fullscreen-section").forEach((sec) => {
        sec.style.display = "none"
      })

      // Show the selected section
      section.style.display = "block"

      // Scroll to top of section
      section.scrollTop = 0
    })
  })

  closeButtons.forEach((button) => {
    button.addEventListener("click", () => {
      fullscreenSections.style.display = "none"
      document.body.style.overflow = "auto"
    })
  })

  // Close fullscreen when clicking outside content
  fullscreenSections.addEventListener("click", (e) => {
    if (e.target === fullscreenSections) {
      fullscreenSections.style.display = "none"
      document.body.style.overflow = "auto"
    }
  })

  // Mobile menu toggle
  const menuToggle = document.querySelector(".menu-toggle")
  const navLinks = document.querySelector(".nav-links")

  if (menuToggle && navLinks) {
    menuToggle.addEventListener("click", () => {
      navLinks.classList.toggle("active")
      const bars = document.querySelectorAll(".bar")
      bars.forEach((bar) => bar.classList.toggle("active"))
    })
  }

  // Quiz functionality
  const quizData = [
    // Introducere
    {
      question: "În ce perioadă s-a desfășurat Al Doilea Război Mondial?",
      options: ["1914-1918", "1939-1945", "1941-1945", "1937-1944"],
      correctAnswer: 1,
      category: "introducere",
    },
    {
      question: "Câte victime a provocat Al Doilea Război Mondial la nivel global?",
      options: [
        "Aproximativ 20 de milioane",
        "Aproximativ 50 de milioane",
        "Între 70 și 85 de milioane",
        "Peste 100 de milioane",
      ],
      correctAnswer: 2,
      category: "introducere",
    },
    {
      question: "Care a fost poziția inițială a României la începutul celui de-al Doilea Război Mondial?",
      options: ["Alianța cu Germania", "Alianța cu URSS", "Neutralitate", "Alianța cu Marea Britanie"],
      correctAnswer: 2,
      category: "introducere",
    },

    // Neutralitate
    {
      question: "Ce teritorii a pierdut România în vara anului 1940?",
      options: [
        "Doar Transilvania de Nord",
        "Basarabia, Bucovina de Nord și Cadrilaterul",
        "Basarabia, Bucovina de Nord, Transilvania de Nord și Cadrilaterul",
        "Doar Basarabia și Bucovina de Nord",
      ],
      correctAnswer: 2,
      category: "neutralitate",
    },
    {
      question: "Prin ce document diplomatic a pierdut România Transilvania de Nord?",
      options: ["Pactul Ribbentrop-Molotov", "Dictatul de la Viena", "Tratatul de la Craiova", "Ultimatumul sovietic"],
      correctAnswer: 1,
      category: "neutralitate",
    },
    {
      question: "Ce eveniment politic major a avut loc în România după pierderile teritoriale din 1940?",
      options: [
        "Abdicarea Regelui Carol al II-lea",
        "Instaurarea republicii",
        "Formarea unui guvern de coaliție",
        "Intrarea în război alături de Aliați",
      ],
      correctAnswer: 0,
      category: "neutralitate",
    },

    // Axa
    {
      question: "Când a aderat oficial România la Pactul Tripartit?",
      options: ["23 august 1939", "23 noiembrie 1940", "22 iunie 1941", "23 august 1944"],
      correctAnswer: 1,
      category: "axa",
    },
    {
      question: "Care a fost principalul motiv al intrării României în război alături de Germania?",
      options: [
        "Presiunea economică germană",
        "Recuperarea Basarabiei și Bucovinei de Nord",
        "Alianța tradițională cu Germania",
        "Teama de Marea Britanie",
      ],
      correctAnswer: 1,
      category: "axa",
    },
    {
      question: "Ce eveniment intern important a avut loc în ianuarie 1941 în România?",
      options: [
        "Abdicarea regelui",
        "Rebeliunea legionară",
        "Formarea unui nou guvern de coaliție",
        "Proclamarea republicii",
      ],
      correctAnswer: 1,
      category: "axa",
    },

    // Front Est
    {
      question: "Când a intrat România în război împotriva Uniunii Sovietice?",
      options: ["1 septembrie 1939", "22 iunie 1941", "23 august 1944", "9 mai 1945"],
      correctAnswer: 1,
      category: "front-est",
    },
    {
      question: "Care a fost ordinul celebru dat de mareșalul Antonescu la începutul războiului împotriva URSS?",
      options: [
        "Soldați, vă ordon: apărați patria!",
        "Ostași, vă ordon: treceți Prutul!",
        "Români, a sosit ceasul răzbunării!",
        "Armata română, înainte marș!",
      ],
      correctAnswer: 1,
      category: "front-est",
    },
    {
      question: "Ce bătălie a reprezentat un dezastru pentru armata română pe Frontul de Est?",
      options: ["Bătălia pentru Odessa", "Bătălia pentru Moscova", "Bătălia de la Stalingrad", "Bătălia pentru Berlin"],
      correctAnswer: 2,
      category: "front-est",
    },

    // Schimbare
    {
      question: "Când a avut loc actul de la 23 august 1944?",
      options: ["23 august 1939", "23 august 1941", "23 august 1944", "23 august 1945"],
      correctAnswer: 2,
      category: "schimbare",
    },
    {
      question: "Cine a fost principalul artizan al actului de la 23 august 1944?",
      options: ["Ion Antonescu", "Regele Mihai I", "Petru Groza", "Gheorghe Gheorghiu-Dej"],
      correctAnswer: 1,
      category: "schimbare",
    },
    {
      question: "Ce s-a întâmplat cu mareșalul Antonescu în ziua de 23 august 1944?",
      options: ["A fugit din țară", "A fost arestat", "A demisionat", "A fost executat"],
      correctAnswer: 1,
      category: "schimbare",
    },

    // Consecințe
    {
      question: "Ce teritorii a pierdut definitiv România după Al Doilea Război Mondial?",
      options: [
        "Transilvania de Nord",
        "Basarabia, Bucovina de Nord și Ținutul Herța",
        "Cadrilaterul",
        "Toate teritoriile menționate",
      ],
      correctAnswer: 1,
      category: "consecinte",
    },
    {
      question: "Când a fost semnat Tratatul de Pace de la Paris pentru România?",
      options: ["23 august 1944", "9 mai 1945", "10 februarie 1947", "30 decembrie 1947"],
      correctAnswer: 2,
      category: "consecinte",
    },
    {
      question: "Care a fost una dintre consecințele majore ale războiului pentru România?",
      options: [
        "Integrarea în NATO",
        "Ocupația sovietică și instaurarea regimului comunist",
        "Dezvoltarea economică rapidă",
        "Alianța cu SUA",
      ],
      correctAnswer: 1,
      category: "consecinte",
    },
  ]

  // Amestecă întrebările
  const shuffledQuizData = [...quizData].sort(() => Math.random() - 0.5)

  let currentQuestionIndex = 0
  const userAnswers = []

  const quizContent = document.getElementById("quiz-content")
  const prevQuestionButton = document.getElementById("prev-question")
  const nextQuestionButton = document.getElementById("next-question")
  const submitButton = document.getElementById("submit-quiz")
  const progressFill = document.querySelector(".progress-fill")
  const currentQuestionElement = document.getElementById("current-question")
  const totalQuestionsElement = document.getElementById("total-questions")
  const totalQuestionsResultElement = document.getElementById("total-questions-result")

  // Inițializare quiz
  const initQuiz = () => {
    totalQuestionsElement.textContent = shuffledQuizData.length
    totalQuestionsResultElement.textContent = shuffledQuizData.length
    showQuestion(0)
  }

  // Afișează întrebarea curentă
  const showQuestion = (index) => {
    const question = shuffledQuizData[index]
    currentQuestionElement.textContent = index + 1

    // Actualizează progress bar
    const progressPercentage = ((index + 1) / shuffledQuizData.length) * 100
    progressFill.style.width = `${progressPercentage}%`

    // Creează conținutul întrebării
    const questionHTML = `
      <div class="question-container">
        <div class="question-text">${index + 1}. ${question.question}</div>
        <div class="options-container">
          ${question.options
            .map(
              (option, i) => `
            <div class="option-item ${userAnswers[index] === i ? "selected" : ""}" data-index="${i}">
              <div class="option-marker">${String.fromCharCode(65 + i)}</div>
              <div class="option-text">${option}</div>
            </div>
          `,
            )
            .join("")}
        </div>
      </div>
    `

    quizContent.innerHTML = questionHTML

    // Adaugă event listeners pentru opțiuni
    const optionItems = document.querySelectorAll(".option-item")
    optionItems.forEach((item) => {
      item.addEventListener("click", () => {
        const optionIndex = Number.parseInt(item.dataset.index)
        userAnswers[currentQuestionIndex] = optionIndex

        // Deselectează toate opțiunile
        optionItems.forEach((opt) => opt.classList.remove("selected"))

        // Selectează opțiunea curentă
        item.classList.add("selected")
      })
    })

    // Actualizează butoanele de navigare
    prevQuestionButton.disabled = index === 0

    if (index === shuffledQuizData.length - 1) {
      nextQuestionButton.style.display = "none"
      submitButton.style.display = "block"
    } else {
      nextQuestionButton.style.display = "block"
      submitButton.style.display = "none"
    }
  }

  // Event listeners pentru butoanele de navigare
  prevQuestionButton.addEventListener("click", () => {
    if (currentQuestionIndex > 0) {
      currentQuestionIndex--
      showQuestion(currentQuestionIndex)
    }
  })

  nextQuestionButton.addEventListener("click", () => {
    if (currentQuestionIndex < shuffledQuizData.length - 1) {
      currentQuestionIndex++
      showQuestion(currentQuestionIndex)
    }
  })

  // Calculează și afișează rezultatele
  submitButton.addEventListener("click", () => {
    const quizContainer = document.querySelector(".quiz-container")
    const quizResults = document.getElementById("quiz-results")
    const scorePercentage = document.getElementById("score-percentage")
    const correctAnswers = document.getElementById("correct-answers")
    const resultsFeedback = document.getElementById("results-feedback")

    // Calculează scorul
    let score = 0
    const categoryScores = {}
    const categoryQuestions = {}

    shuffledQuizData.forEach((question, index) => {
      const category = question.category

      if (!categoryScores[category]) {
        categoryScores[category] = 0
        categoryQuestions[category] = 0
      }

      categoryQuestions[category]++

      if (userAnswers[index] === question.correctAnswer) {
        score++
        categoryScores[category]++
      }
    })

    const percentage = Math.round((score / shuffledQuizData.length) * 100)

    // Actualizează elementele UI
    scorePercentage.textContent = `${percentage}%`
    correctAnswers.textContent = score

    // Generează feedback pentru fiecare categorie
    let feedbackHTML = "<h4>Detalii pe categorii:</h4><ul>"

    for (const category in categoryScores) {
      const categoryPercentage = Math.round((categoryScores[category] / categoryQuestions[category]) * 100)
      let categoryName = ""

      switch (category) {
        case "introducere":
          categoryName = "Introducere"
          break
        case "neutralitate":
          categoryName = "Perioada de neutralitate"
          break
        case "axa":
          categoryName = "Alianța cu Puterile Axei"
          break
        case "front-est":
          categoryName = "Frontul de Est"
          break
        case "schimbare":
          categoryName = "Schimbarea alianței"
          break
        case "consecinte":
          categoryName = "Consecințele războiului"
          break
      }

      let performanceText = ""
      if (categoryPercentage === 100) {
        performanceText = "Excelent! Stăpânești foarte bine acest subiect."
      } else if (categoryPercentage >= 70) {
        performanceText = "Bine! Ai cunoștințe solide despre acest subiect."
      } else if (categoryPercentage >= 40) {
        performanceText = "Poți mai mult! Recitește secțiunea pentru a-ți îmbunătăți cunoștințele."
      } else {
        performanceText = "Ar fi bine să recitești cu atenție această secțiune."
      }

      feedbackHTML += `
        <li>
          <strong>${categoryName}:</strong> ${categoryScores[category]}/${categoryQuestions[category]} răspunsuri corecte (${categoryPercentage}%)
          <p>${performanceText}</p>
        </li>
      `
    }

    feedbackHTML += "</ul>"

    // Adaugă feedback general
    feedbackHTML += "<h4>Feedback general:</h4><p>"

    if (percentage >= 90) {
      feedbackHTML += "Felicitări! Ai o înțelegere excelentă a participării României în Al Doilea Război Mondial."
    } else if (percentage >= 70) {
      feedbackHTML += "Bine! Ai cunoștințe solide despre participarea României în Al Doilea Război Mondial."
    } else if (percentage >= 50) {
      feedbackHTML += "Ai o înțelegere de bază a subiectului, dar mai este loc de îmbunătățire."
    } else {
      feedbackHTML +=
        "Ar fi bine să recitești materialul pentru a-ți îmbunătăți cunoștințele despre acest subiect important."
    }

    feedbackHTML += "</p>"

    resultsFeedback.innerHTML = feedbackHTML

    // Actualizează stilul cercului de scor
    const scoreCircle = document.querySelector(".score-circle")
    scoreCircle.style.background = `conic-gradient(
      var(--primary-color) 0%,
      var(--secondary-color) ${percentage / 2}%,
      var(--accent-color) ${percentage}%,
      #e0e0e0 ${percentage}%,
      #e0e0e0 100%
    )`

    // Afișează rezultatele
    quizContainer.style.display = "none"
    quizResults.style.display = "block"
  })

  // Restart quiz
  document.getElementById("restart-quiz").addEventListener("click", () => {
    // Resetează variabilele
    currentQuestionIndex = 0
    userAnswers.length = 0

    // Amestecă din nou întrebările
    shuffledQuizData.sort(() => Math.random() - 0.5)

    // Resetează UI
    document.querySelector(".quiz-container").style.display = "block"
    document.getElementById("quiz-results").style.display = "none"

    // Afișează prima întrebare
    showQuestion(0)
  })

  // Smooth scroll pentru link-uri de navigare
  document.querySelectorAll('a[href^="#"]').forEach((anchor) => {
    anchor.addEventListener("click", function (e) {
      e.preventDefault()

      const targetId = this.getAttribute("href")
      const targetElement = document.querySelector(targetId)

      if (targetElement) {
        window.scrollTo({
          top: targetElement.offsetTop - 70,
          behavior: "smooth",
        })

        // Închide meniul mobil dacă este deschis
        if (navLinks && navLinks.classList.contains("active")) {
          navLinks.classList.remove("active")
          const bars = document.querySelectorAll(".bar")
          bars.forEach((bar) => bar.classList.remove("active"))
        }
      }
    })
  })

  // Inițializează quiz-ul
  if (document.getElementById("quiz-content")) {
    initQuiz()
  }
})
