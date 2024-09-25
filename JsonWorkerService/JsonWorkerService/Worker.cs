using JsonWorkerService.Models;
using Newtonsoft.Json;

namespace JsonWorkerService;
using System.Net.Http;
public class Worker : BackgroundService
{
    private readonly ILogger<Worker> _logger;

    public Worker(ILogger<Worker> logger)
    {
        _logger = logger;
    }

    protected override async Task ExecuteAsync(CancellationToken stoppingToken)
    {
        while (!stoppingToken.IsCancellationRequested)
        {
            //_logger.LogInformation("Worker running at: {time}", DateTimeOffset.Now);
            GetUsers();
            await Task.Delay(100000, stoppingToken);
        }
    }

    private async void GetUsers()
    {
        using (HttpClient client = new HttpClient())
        {
            client.DefaultRequestHeaders.Add("X-Access-Key", "$2a$10$B27YEKYz4UFtpGWJw3ETHOeWq.3aQhLQuosXho6mMzawJC5veV70i");
            var response = await client.GetAsync("https://api.jsonbin.io/v3/b/66f32e7cad19ca34f8ac31b5");
            if (response.IsSuccessStatusCode)
            {
                /*var json = await response.Content.ReadAsStringAsync();
                _logger.LogInformation(json);*/
                /*List<Users> users = JsonConvert.DeserializeObject<List<Users>>(await response.Content.ReadAsStreamAsync());
                List<Tickets> tickets = JsonConvert.DeserializeObject<List<Tickets>>(await response.Content.ReadAsStreamAsync());*/
                
                var json = await response.Content.ReadAsStringAsync();
                /*_logger.LogInformation("json: \n");
                _logger.LogInformation(json);*/


                var apiResponse = JsonConvert.DeserializeObject<ApiResponse>(json);
                /*_logger.LogInformation("apiResponse: \n");
                _logger.LogInformation($"{apiResponse}");*/

                if (apiResponse != null)
                {
                    _logger.LogInformation("Users: {");
                    foreach (Users user in apiResponse.Record.Users)
                    {
                        _logger.LogInformation($"\tName: {user.Name}, Email: {user.Email}, ID: {user.Id}");
                    }
                    _logger.LogInformation("}\n");


                    _logger.LogInformation("Tickets: {");
                    foreach (Tickets ticket in apiResponse.Record.Tickets)
                    {
                        _logger.LogInformation($"\tID: {ticket.Id}, Priority: {ticket.Priority}, CC_Emails: {ticket.CcEmails}, Reply_CC_Emails: {ticket.ReplyCcEmails}");
                    }
                    _logger.LogInformation("}\n");
                }
            }
            else
            {
                _logger.LogError($"GetUsers failed with status code {response.StatusCode}");
            }
        }
    }
}