# Testing

> "The process of operating a system or component under specified conditions, observing or recording the results, and making an evaluation of some aspect of the system or component".

> Testing is the process of comparing "what is" with "what ought to be."

> "Testing is a concurrent lifecycle process of engineering, using and maintaining testware in order to measure and improve the quality of the software being tested."

## Five Levels of Testing Maturity

- Level 0 - "There's no difference between testing and debugging"
- Level 1 - "The purpose of testing is to show that software works."
- Level 2 - The purpose of testing is to show that the software doesn't work."
- Level 3- "The purpose of testing is not to prove anything, but to reduce the perceived risk of not working to an acceptable value."Testing goals are to understand the quality of the software in terms of its defects, to furnish the programmers with information about the software's deficiencies, and to provide management with an evaluation of the negative impact on our organization if we shipped this system to customers in its present state
- Level 4 - "Testing is not an act. It is a mental discipline that results in low-risk software without much testing effort." At this maturity level we focus on making software more testable from its inception. This includes reviews and inspections of its requirements, design, and code. In addition, it means writing code that incorporates facilities the tester can easily use to interrogate it while it is executing. Further, it means writing code that is self-diagnosing, that reports errors rather than requiring testers to discover them

### Current Challenges

---

- Not enough time to test properly
- Too many combinations of inputs to test 
- Not enough time to test well
-  Difficulty in determining the expected results of each test
-  Nonexistent or rapidly changing requirements 
- Not enough time to test thoroughly
-  No training in testing processes
-  No tool support 
- Management that either doesn't understand testing or (apparently) doesn't care about quality 
- Not enough time

### : Black Box Testing Techniques

---

- The requirements or specifications are analyzed. 
- Valid inputs are chosen based on the specification to determine that the Software Under Test processes them correctly.
- Invalid inputs must also be chosen to verify that the SUT detects them and handles them properly. 
- Expected outputs for those inputs are determined. 
- Tests are constructed with the selected inputs. The tests are run. Actual outputs are compared with the expected outputs.
-  A determination is made as to the proper functioning of the SUT.
- Advantages : Formal black box testing directs the tester to choose subsets of tests that are both efficient and effective in finding defects. Black box testing helps maximize the return on our testing investment
- Disadvantages : When using black box testing, the tester can never be sure of how much of the SUT has been tested. No matter how clever or diligent the tester, some execution paths may never be exercised. 

```C++
if (name=="Lee" && employeeNumber=="1234" && employmentStatus=="RecentlyTerminatedForCause") {
   send Lee a check for $1,000,000;
}

To find every defect using black box testing, the tester would have to create every possible combination of input data, both valid and invalid.

```

### Black Box Testing  Techniques

---

#### Equivalence Class Testing

> Equivalence class testing is a technique used to reduce the number of test cases to a manageable level while still maintaining reasonable test coverage



