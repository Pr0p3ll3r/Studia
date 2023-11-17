package com.example.IntegrationTesting.controller;
import com.example.IntegrationTesting.domain.StudentEntity;
import com.example.IntegrationTesting.service.StudentService;
import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api")
public class StudentRestController {
    @Autowired
    private StudentService studentService;
    @PostMapping("/students")
    public ResponseEntity<StudentEntity>
    createStudent(@RequestBody StudentEntity student) {
        HttpStatus status = HttpStatus.CREATED;
        StudentEntity saved = studentService.save(student);
        return new ResponseEntity<>(saved, status);
    }
    @GetMapping("/students")
    public List<StudentEntity> getAllStudents() {
        return studentService.getAllStudents();
    }
    @GetMapping("/students/{id}")
    public ResponseEntity<StudentEntity> getStudentById(@PathVariable Long id) {
        HttpStatus status = HttpStatus.OK;
        StudentEntity student = studentService.getStudentById(id);
        return new ResponseEntity<>(student, status);
    }
    @GetMapping("/students/name/{name}")
    public ResponseEntity<StudentEntity> getStudentById(@PathVariable String name) {
        HttpStatus status = HttpStatus.OK;
        StudentEntity student = studentService.getStudentByName(name);
        return new ResponseEntity<>(student, status);
    }
}