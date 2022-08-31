#pragma once
#include <array>
#include <random>
#include <ranges>
#include <string>

namespace scp_7777 {
    template<class T> std::basic_string<T> encode(const std::basic_string<T>& plain_text, size_t total_length, auto seed) {
        std::basic_string<T> cipher_text;
        for (const T& ch : plain_text) {
            cipher_text += std::string(static_cast<size_t>(ch), '7');
            if (&ch != &*plain_text.rbegin()) {
                cipher_text += '0';
            }
        }
        if (total_length > cipher_text.length()) {
            std::default_random_engine engine(seed);
            size_t offset;
            {
                std::uniform_int_distribution<size_t> offset_dist(0, total_length - cipher_text.length());
                offset = offset_dist(engine);
            }
            std::basic_string<T> result;
            std::uniform_int_distribution<int> digit_dist('0', '9');
            for (size_t i : std::views::iota((size_t)0, offset)) {
                result += static_cast<T>(digit_dist(engine));
            }
            result += cipher_text;
            for (size_t i : std::views::iota(result.length(), total_length)) {
                result += digit_dist(engine);
            }
            return result;
        } else {
            return cipher_text;
        }
    }

    template<class T> std::basic_string<T> decode(const std::basic_string<T>& cipher_text) {
        size_t current_value = 0;
        std::basic_string<T> result;
        for (T digit : cipher_text) {
            switch (digit) {
            case '7':
                current_value++;
                break;
            case '0':
            default:
                if (current_value >= ' ') {
                    result += static_cast<T>(current_value);
                }
                current_value = 0;
            }
        }
        if (current_value >= ' ') {
            result += static_cast<T>(current_value);
        }
        return result;
    }

    static const std::array<std::string, 37> instances {
        "Site Director Franklyn Garnett murdered Dr. Theresa Booth on March 11th, 2003, by replacing her medication with Compound Y-909 and framing it as amnestic overdose.",
        "Senior Researcher Jackson Bell sexually assaulted a female researcher during the Site-18 2016 Christmas Party.",
        "Containment Specialist Sofia Rosario falsified her credentials and plagiarized stolen designs from her coworkers.",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "Accountant Gregory Caplin allowed various monetary crimes to occur due to negligence in bookkeeping important projects.",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "Site Director Thomas Graham vandalized SCP-4051's containment chamber with the phrase \"DUMB ANOMALY IDIOT\" to intentionally provoke vim into breaching.",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "Dr. Theron Sherman attacked Junior Researcher Roger Radcliff on September 12th, 2018, in Site-42's break room.",
        "Junior Researcher Roger Radcliff attempted to frame Dr. Theron Sherman using a falsified SCP-7000 instance.",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "Thaumaturgist Diana Ribeiro cast thaumaturgic spells on various Department of Tactical Theology researchers in an attempt to send them to the Abrahamic hell when they died.",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "Director Calvin Bold murdered a six-month-old baby by kicking it into a wall.",
        "Ethics Committee Member Jeremiah Cimmerian intentionally fabricated the SCP-6469 anomaly to protect Director Calvin Bold.",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "[ENTRY EXPUNGED BY ORDER OF THE O5 COUNCIL]",
        "O5-6 is plotting to murder Technician Davis Silverstein."
    };
}
