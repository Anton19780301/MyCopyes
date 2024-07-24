package org.example.sb01.repositories;

import org.example.sb01.entity.Books;
import org.springframework.data.jpa.repository.JpaRepository;

public interface BooksRepo extends JpaRepository<Books, Long>{}
