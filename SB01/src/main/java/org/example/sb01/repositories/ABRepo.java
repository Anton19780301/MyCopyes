package org.example.sb01.repositories;

import org.example.sb01.entity.AuthorsBooks;
import org.springframework.data.jpa.repository.JpaRepository;

public interface ABRepo extends JpaRepository<AuthorsBooks, Long> {}
