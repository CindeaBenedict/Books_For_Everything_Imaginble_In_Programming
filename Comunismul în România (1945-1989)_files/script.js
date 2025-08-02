// Funcția pentru a deschide/închide secțiunile
function toggleSection(contentId) {
  const content = document.getElementById(contentId)
  const header = content.previousElementSibling
  const icon = header.querySelector(".toggle-icon")

  if (content.style.display === "block") {
    content.style.display = "none"
    icon.textContent = "+"
  } else {
    content.style.display = "block"
    icon.textContent = "-"
  }
}

// Deschide prima secțiune la încărcarea paginii
document.addEventListener("DOMContentLoaded", () => {
  const firstSection = document.querySelector(".section-content")
  const firstHeader = firstSection.previousElementSibling
  const firstIcon = firstHeader.querySelector(".toggle-icon")

  firstSection.style.display = "block"
  firstIcon.textContent = "-"

  // Generează quiz-urile pentru fiecare secțiune
  generateQuizzes()

  // Inițializează particles.js
  initParticles()

  // Adaugă efect de scroll smooth pentru navigare
  addSmoothScrolling()
})

// Funcția pentru a inițializa particles.js
function initParticles() {
  // Verifică dacă particlesJS este definit înainte de a-l utiliza
  if (typeof particlesJS !== "undefined") {
    particlesJS("particles-js", {
      particles: {
        number: {
          value: 50,
          density: {
            enable: true,
            value_area: 800,
          },
        },
        color: {
          value: "#b71c1c",
        },
        shape: {
          type: "circle",
          stroke: {
            width: 0,
            color: "#000000",
          },
          polygon: {
            nb_sides: 5,
          },
        },
        opacity: {
          value: 0.3,
          random: true,
          anim: {
            enable: true,
            speed: 1,
            opacity_min: 0.1,
            sync: false,
          },
        },
        size: {
          value: 3,
          random: true,
          anim: {
            enable: true,
            speed: 2,
            size_min: 0.1,
            sync: false,
          },
        },
        line_linked: {
          enable: true,
          distance: 150,
          color: "#b71c1c",
          opacity: 0.2,
          width: 1,
        },
        move: {
          enable: true,
          speed: 1,
          direction: "none",
          random: true,
          straight: false,
          out_mode: "out",
          bounce: false,
          attract: {
            enable: false,
            rotateX: 600,
            rotateY: 1200,
          },
        },
      },
      interactivity: {
        detect_on: "canvas",
        events: {
          onhover: {
            enable: true,
            mode: "grab",
          },
          onclick: {
            enable: true,
            mode: "push",
          },
          resize: true,
        },
        modes: {
          grab: {
            distance: 140,
            line_linked: {
              opacity: 0.5,
            },
          },
          bubble: {
            distance: 400,
            size: 40,
            duration: 2,
            opacity: 8,
            speed: 3,
          },
          repulse: {
            distance: 200,
            duration: 0.4,
          },
          push: {
            particles_nb: 4,
          },
          remove: {
            particles_nb: 2,
          },
        },
      },
      retina_detect: true,
    })
  } else {
    console.warn("particlesJS is not defined. Make sure the particles.js library is included.")
  }
}

// Adaugă smooth scrolling pentru navigare
function addSmoothScrolling() {
  document.querySelectorAll("nav a").forEach((anchor) => {
    anchor.addEventListener("click", function (e) {
      e.preventDefault()

      const targetId = this.getAttribute("href")
      const targetElement = document.querySelector(targetId)

      if (targetElement) {
        window.scrollTo({
          top: targetElement.offsetTop - 100,
          behavior: "smooth",
        })

        // Deschide secțiunea dacă este închisă
        const contentId = targetId.substring(1) + "-content"
        const content = document.getElementById(contentId)

        if (content && content.style.display !== "block") {
          toggleSection(contentId)
        }
      }
    })
  })
}

// Întrebările pentru fiecare secțiune
const quizData = {
  introducere: [
    {
      question: "Cât timp a durat perioada comunistă în România?",
      options: ["Aproximativ 25 de ani", "Aproximativ 35 de ani", "Aproximativ 45 de ani", "Aproximativ 55 de ani"],
      correctAnswer: 2,
    },
    {
      question: "Care dintre următoarele NU a fost o caracteristică a comunismului românesc?",
      options: [
        "Naționalizarea proprietăților private",
        "Economia de piață liberă",
        "Colectivizarea agriculturii",
        "Controlul strict al vieții sociale",
      ],
      correctAnswer: 1,
    },
    {
      question: "Cum a fost regimul comunist din România în comparație cu alte regimuri din blocul estic?",
      options: [
        "Unul dintre cele mai liberale",
        "Unul dintre cele mai represive",
        "Cel mai prosper economic",
        "Cel mai democratic",
      ],
      correctAnswer: 1,
    },
  ],
  instaurare: [
    {
      question: "Când a fost proclamată Republica Populară Română?",
      options: ["1945", "1947", "1948", "1950"],
      correctAnswer: 1,
    },
    {
      question: "Cine a fost primul lider comunist important al României?",
      options: ["Nicolae Ceaușescu", "Gheorghe Gheorghiu-Dej", "Petru Groza", "Ana Pauker"],
      correctAnswer: 1,
    },
    {
      question: "În ce an a fost înființată Securitatea?",
      options: ["1945", "1947", "1948", "1950"],
      correctAnswer: 2,
    },
  ],
  ceausescu: [
    {
      question: "În ce an a preluat Nicolae Ceaușescu conducerea Partidului Comunist Român?",
      options: ["1960", "1965", "1970", "1975"],
      correctAnswer: 1,
    },
    {
      question: "Care eveniment a contribuit la creșterea popularității lui Ceaușescu în primii ani de conducere?",
      options: [
        "Condamnarea invaziei sovietice în Cehoslovacia (1968)",
        "Vizita în China",
        "Achitarea datoriei externe",
        "Construirea Casei Poporului",
      ],
      correctAnswer: 0,
    },
    {
      question: 'Ce a marcat "Tezele din iulie" (1971)?',
      options: [
        "Liberalizarea economiei",
        "Deschiderea către Occident",
        "Revenirea la un control ideologic strict asupra culturii",
        "Îmbunătățirea relațiilor cu URSS",
      ],
      correctAnswer: 2,
    },
  ],
  "viata-cotidiana": [
    {
      question: "Care a fost una dintre principalele probleme ale vieții cotidiene în anii '80?",
      options: [
        "Prețurile prea mari la alimente",
        "Raționalizarea alimentelor și cozile la magazine",
        "Lipsa locuințelor",
        "Taxele prea mari",
      ],
      correctAnswer: 1,
    },
    {
      question: "Câte ore pe zi difuza televiziunea română în anii '80?",
      options: ["24 de ore", "12 ore", "6 ore", "Aproximativ 2 ore"],
      correctAnswer: 3,
    },
    {
      question: "Care dintre următoarele afirmații despre educația în perioada comunistă este adevărată?",
      options: [
        "Era accesibilă doar elitelor",
        "Era gratuită dar puternic ideologizată",
        "Era complet lipsită de valoare",
        "Era identică cu sistemul occidental",
      ],
      correctAnswer: 1,
    },
  ],
  represiune: [
    {
      question: "Care a fost principalul instrument al represiunii în România comunistă?",
      options: ["Armata", "Miliția", "Securitatea", "Partidul Comunist"],
      correctAnswer: 2,
    },
    {
      question: 'Ce a fost "Experimentul Pitești"?',
      options: [
        "Un program de cercetare științifică",
        'Un program brutal de "reeducare" a deținuților politici',
        "O reformă economică",
        "Un experiment social în mediul rural",
      ],
      correctAnswer: 1,
    },
    {
      question: "Până când a continuat rezistența armată anticomunistă în munți?",
      options: [
        "Până la sfârșitul anilor '40",
        "Până la începutul anilor '60",
        "Până la mijlocul anilor '70",
        "Până în 1989",
      ],
      correctAnswer: 1,
    },
  ],
  revolutie: [
    {
      question: "Unde au început protestele care au dus la Revoluția din 1989?",
      options: ["București", "Timișoara", "Brașov", "Cluj"],
      correctAnswer: 1,
    },
    {
      question: "Când au fost executați Nicolae și Elena Ceaușescu?",
      options: ["22 decembrie 1989", "24 decembrie 1989", "25 decembrie 1989", "1 ianuarie 1990"],
      correctAnswer: 2,
    },
    {
      question: "Ce a fost Frontul Salvării Naționale (FSN)?",
      options: [
        "O organizație de rezistență anticomunistă",
        "Organizația care a preluat puterea după fuga lui Ceaușescu",
        "Un partid politic format înainte de 1989",
        "O organizație internațională",
      ],
      correctAnswer: 1,
    },
  ],
}

// Funcția pentru a genera quiz-urile
function generateQuizzes() {
  for (const section in quizData) {
    const quizContainer = document.getElementById(`quiz-${section}`)
    const questions = quizData[section]

    // Amestecă ordinea întrebărilor
    const shuffledQuestions = [...questions].sort(() => Math.random() - 0.5)

    shuffledQuestions.forEach((q, qIndex) => {
      const questionDiv = document.createElement("div")
      questionDiv.className = "question"
      questionDiv.dataset.originalIndex = questions.indexOf(q)

      const questionText = document.createElement("p")
      questionText.textContent = `${qIndex + 1}. ${q.question}`
      questionDiv.appendChild(questionText)

      const optionsDiv = document.createElement("div")
      optionsDiv.className = "options"

      // Amestecă ordinea opțiunilor
      const shuffledOptions = [...q.options]
        .map((option, index) => {
          return {
            text: option,
            originalIndex: index,
          }
        })
        .sort(() => Math.random() - 0.5)

      shuffledOptions.forEach((option, oIndex) => {
        const optionDiv = document.createElement("div")
        optionDiv.className = "option"
        optionDiv.textContent = `${String.fromCharCode(97 + oIndex)}. ${option.text}`
        optionDiv.dataset.originalIndex = option.originalIndex
        optionDiv.dataset.questionIndex = questionDiv.dataset.originalIndex

        optionDiv.addEventListener("click", function () {
          // Deselectează toate opțiunile pentru această întrebare
          const siblings = this.parentElement.querySelectorAll(".option")
          siblings.forEach((sib) => sib.classList.remove("selected"))

          // Selectează această opțiune
          this.classList.add("selected")
        })

        optionsDiv.appendChild(optionDiv)
      })

      questionDiv.appendChild(optionsDiv)
      quizContainer.appendChild(questionDiv)
    })
  }
}

// Funcția pentru a verifica răspunsurile
function checkAnswers(section) {
  const quizContainer = document.getElementById(`quiz-${section}`)
  const scoreContainer = document.getElementById(`score-${section}`)
  const questions = quizContainer.querySelectorAll(".question")

  let score = 0
  const totalQuestions = questions.length

  questions.forEach((question, qIndex) => {
    const selectedOption = question.querySelector(".option.selected")
    const options = question.querySelectorAll(".option")

    // Resetează clasele pentru corect/incorect
    options.forEach((opt) => {
      opt.classList.remove("correct", "incorrect")
    })

    if (selectedOption) {
      const originalIndex = Number.parseInt(selectedOption.dataset.originalIndex)
      const questionIndex = Number.parseInt(selectedOption.dataset.questionIndex)
      const correctAnswer = quizData[section][questionIndex].correctAnswer

      if (originalIndex === correctAnswer) {
        selectedOption.classList.add("correct")
        score++
      } else {
        selectedOption.classList.add("incorrect")

        // Marchează răspunsul corect
        options.forEach((opt) => {
          if (Number.parseInt(opt.dataset.originalIndex) === correctAnswer) {
            opt.classList.add("correct")
          }
        })
      }
    } else {
      // Marchează răspunsul corect dacă utilizatorul nu a selectat nimic
      const questionIndex = Number.parseInt(options[0].dataset.questionIndex)
      const correctAnswer = quizData[section][questionIndex].correctAnswer

      options.forEach((opt) => {
        if (Number.parseInt(opt.dataset.originalIndex) === correctAnswer) {
          opt.classList.add("correct")
        }
      })
    }
  })

  // Afișează scorul
  const percentage = Math.round((score / totalQuestions) * 100)
  scoreContainer.textContent = `Scor: ${score}/${totalQuestions} (${percentage}%)`

  // Adaugă un mesaj în funcție de scor
  let message = ""
  if (percentage === 100) {
    message = " Excelent! Cunoști foarte bine acest subiect!"
  } else if (percentage >= 70) {
    message = " Bine! Ai cunoștințe solide despre acest subiect."
  } else if (percentage >= 40) {
    message = " Poți mai mult! Recitește secțiunea pentru a-ți îmbunătăți cunoștințele."
  } else {
    message = " Ar fi bine să recitești cu atenție această secțiune."
  }

  scoreContainer.textContent += message

  // Adaugă animație pentru scor
  scoreContainer.style.animation = "none"
  setTimeout(() => {
    scoreContainer.style.animation = "fadeInUp 0.5s"
  }, 10)
}

// Funcția pentru a reseta quiz-ul
function resetQuiz(section) {
  const quizContainer = document.getElementById(`quiz-${section}`)
  const scoreContainer = document.getElementById(`score-${section}`)

  // Șterge conținutul containerului de scor
  scoreContainer.textContent = ""

  // Resetează toate opțiunile selectate și clasele de corect/incorect
  const options = quizContainer.querySelectorAll(".option")
  options.forEach((option) => {
    option.classList.remove("selected", "correct", "incorrect")
  })

  // Adaugă animație de fade pentru quiz
  quizContainer.style.opacity = "0"
  setTimeout(() => {
    // Șterge toate întrebările existente
    quizContainer.innerHTML = ""

    // Regenerează quiz-ul cu întrebări și opțiuni în ordine aleatorie
    const questions = quizData[section]

    // Amestecă ordinea întrebărilor
    const shuffledQuestions = [...questions].sort(() => Math.random() - 0.5)

    shuffledQuestions.forEach((q, qIndex) => {
      const questionDiv = document.createElement("div")
      questionDiv.className = "question"
      questionDiv.dataset.originalIndex = questions.indexOf(q)

      const questionText = document.createElement("p")
      questionText.textContent = `${qIndex + 1}. ${q.question}`
      questionDiv.appendChild(questionText)

      const optionsDiv = document.createElement("div")
      optionsDiv.className = "options"

      // Amestecă ordinea opțiunilor
      const shuffledOptions = [...q.options]
        .map((option, index) => {
          return {
            text: option,
            originalIndex: index,
          }
        })
        .sort(() => Math.random() - 0.5)

      shuffledOptions.forEach((option, oIndex) => {
        const optionDiv = document.createElement("div")
        optionDiv.className = "option"
        optionDiv.textContent = `${String.fromCharCode(97 + oIndex)}. ${option.text}`
        optionDiv.dataset.originalIndex = option.originalIndex
        optionDiv.dataset.questionIndex = questionDiv.dataset.originalIndex

        optionDiv.addEventListener("click", function () {
          // Deselectează toate opțiunile pentru această întrebare
          const siblings = this.parentElement.querySelectorAll(".option")
          siblings.forEach((sib) => sib.classList.remove("selected"))

          // Selectează această opțiune
          this.classList.add("selected")
        })

        optionsDiv.appendChild(optionDiv)
      })

      questionDiv.appendChild(optionsDiv)
      quizContainer.appendChild(questionDiv)
    })

    // Readuce quiz-ul la vizibilitate
    quizContainer.style.opacity = "1"
    quizContainer.style.transition = "opacity 0.5s ease"
  }, 300)
}
