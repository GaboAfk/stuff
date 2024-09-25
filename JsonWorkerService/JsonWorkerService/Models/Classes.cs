namespace JsonWorkerService.Models
{
    public class Users
    {
        public string Name { get; set; }
        public string Email { get; set; }
        public int Id { get; set; }
    }

    public class Tickets
    {
        public int Id { get; set; }
        public int Priority { get; set; }
        public List<string> CcEmails { get; set; }
        public List<string> ReplyCcEmails { get; set; }
    }

    public class Record
    {
        public List<Users> Users { get; set; }
        public List<Tickets> Tickets { get; set; }
    }

    public class ApiResponse
    {
        public Record Record { get; set; }
    }
}