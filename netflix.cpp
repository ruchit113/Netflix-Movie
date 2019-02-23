//
// Netflix Movie Review Analysis
//
// Name: Ruchit Patel
//
// University of Illinois at Chicago


#include<iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// movie class
class Movie
{
private:
	int MovieID, PubYear, Removie, RatingM;
	double AvgratM;
	string MovieName;
	int star1 = 0, star2 = 0, star3 = 0, star4 = 0, star5 = 0, allStar = 0;

public:

	// Construtor of class

	Movie(int movieid, string moviename, int pubyear, int removie, int ratingM, double avgratM)
		:MovieID(movieid), MovieName(moviename), PubYear(pubyear),Removie(removie), RatingM(ratingM), AvgratM(avgratM)
	{
		
	}
	
	string getNameMovie() const
	{
		return MovieName;   // return name
	}

	
	int getMovieid() const
	{
		return MovieID;  // return movie id
	}

	void setId()
	{
		Removie = Removie + 1;  // set id
	}

	int getPubYear() const
	{
		return PubYear;  // return year
	}
	

	// Function count star of movies
	void setRating(int rev)
	{
		RatingM = rev + RatingM;

		if (rev == 1)
		{
			star1 = star1 + 1;
		}
		else if (rev == 2)
		{
			star2 = star2 + 1;
		}
		else if (rev == 3)
		{
			star3 = star3 + 1;
		}
		else if (rev == 4)
		{
			star4 = star4 + 1;
		}
		else
		{
			star5 = star5 + 1;
		}

		allStar = star1 + star2 + star3 + star4 + star5;

	}

	// Number of all star	
	int getallStarcount() const
	{
		return allStar;     // return total number of reviews
	}

	// return number of review
	int getRevi() const
	{
		return Removie;
	}


	// return number of rating
	int totalRati() const
	{
		return RatingM;
	}


	// set Avg rating
	void avgRatingeach(double average)
	{
		AvgratM = average;
	}

	// return rating
	double avgRat() const
	{
		return AvgratM;
	}

	// return star 1 count
	int getStar1() const
	{
		return star1;
	}

	// return star 2 count
	int getStar2() const
	{
		return star2;
	}

	// return star 3 count
	int getStar3() const
	{
		return star3;
	}

	// return star 4 count
	int getStar4() const
	{
		return star4;
	}

	// return star 5 count
	int getStar5() const
	{
		return star5;
	}

};


class Review
{

private:

	int ReviewId, MovieIDr, UserId, Rating;
	string Reviewdate, NameMovie;

public:
	
	// constructor of class

	Review(int reviewid, int movieidr, int userid, int rating, string reviewdate )
		:ReviewId(reviewid), MovieIDr(movieidr), UserId(userid), Rating(rating), Reviewdate(reviewdate)
	{

	}


	// return movie id
	int revMoviId() const
	{
		return MovieIDr;
	}

	// return rating
	int revRating() const
	{
		return Rating;
	}

	// return movie id
	int getrevID() const
	{
		return ReviewId;
	}

	// return user id
	int getUserID() const
	{
		return UserId;
	}

	
	string getRevDate() const
	{
		return Reviewdate;
	}

	
};


// Function return average of movie
double getTotalrat(double a, double b)
{

	double c = 0;

	if (a == 0)
	{
		return 0;
	}

	c = b / a;

	return c;

}


// sort vector by average
void sortByAvg(vector<Movie>& movie)
{
	int i = 1;

	// sort vector by averahe rating

	sort(movie.begin(), movie.end(),
		[](Movie& a, Movie& b)
	{
		if (a.avgRat() > b.avgRat())
			return true;
		else if (a.avgRat() < b.avgRat())
			return false;
		else
		{
			if (a.getNameMovie() < b.getNameMovie())
				return true;
			else
				return false;
		}
	});

	
	cout << "Rank " << "   ID " << "   Reviews " << "  Avg  " << "     Name  " << endl;

		// print top 10 movies
		for (auto& cu : movie)
		{
			cout << i << "." << setw(4) << "   " << setw(4)
				 << cu.getMovieid() << setw(4) << "  " << setw(4) << cu.getRevi()
				 << setw(4) << "     " << setw(4) << cu.avgRat() << setw(4) << "  "
				 << "'" << cu.getNameMovie() << "'" << endl;
			i++;
			
			if (i == 11)
			{
				break;
			}

		}
			
		
}

// Add elements vector to map
map<int, Movie> moviemap(const vector<Movie>& movie)
{
	map<int, Movie> M;

	for (Movie ss : movie)
	{
		M.insert(pair<int, Movie>(ss.getMovieid(), ss));
	}

	return M;
}

// Function to look movie id
void lookMovieID(const map<int, Movie>& M, int movieId)
{
	auto iter = M.find(movieId);

	if (iter == M.end())
	{
		cout << endl << "movie not found... " << endl;
	}

	// print all data
	else
	{
		cout << endl << "Movie:"<< "  " << setw(4) << "'" << iter->second.getNameMovie() << "'" << endl;
		cout << "Year:" << "  " << setw(4) << iter->second.getPubYear() << endl;
		cout << "Avg rating:" << setw(4) << iter->second.avgRat() << endl;
		cout << "Num reviews: " << setw(4) << iter->second.getallStarcount() << endl;
		cout << "  1 star:  " << setw(4) << iter->second.getStar1() << endl;
		cout << "  2 star:  " << setw(4) << iter->second.getStar2() << endl;
		cout << "  3 star:  " << setw(4) << iter->second.getStar3() << endl;
		cout << "  4 star:  " << setw(4) << iter->second.getStar4() << endl;
		cout << "  5 star:  " << setw(4) << iter->second.getStar5() << endl;

	} 

}


// Add elements vector to map
map<int, Review> reviewmap(const vector<Review>& review)
{
	map<int, Review> R;

	for (Review rr : review)
	{
		R.insert(pair<int, Review>(rr.getrevID(), rr));
	}

	return R;

}

// function to look review id
void lookReviewID(const map<int, Review>& R, int revId, const vector<Movie>& movie)
{
	auto iter = R.find(revId);

	if (iter == R.end())
	{
		cout << endl << "review not found..." << endl;
	}
	else
	{
		// print all data

		cout << endl << "Movie: " << setw(4) << iter->second.revMoviId();

		auto iter2 = find_if(movie.begin(), movie.end(),[&] (Movie m)
		{
			if (iter->second.revMoviId() == m.getMovieid())
				return true;
			else
				return false;
		});
		
		if (iter2 == movie.end())
		{
			cout << "Not found" << endl;
		}
		else
			cout << " ("<< iter2->getNameMovie() << " )" << endl;


		cout << "Num star:" << setw(4) << iter->second.revRating() << endl;
		cout << "User Id: " << setw(4) << iter->second.getUserID() << endl;
		cout << "Date:  " << setw(4) << iter->second.getRevDate() << endl;
	}


}






int main() {

	string fileM, fileR;
	string line, movieid,moviename,pubyear;
	string line2, reviewid, movieidre, useridre, ratingre, reviewdate;

	int countMovie = 0;
	int countReview = 0;
	int defRevi = 0, defRati = 0;
	double defAvg = 0;
	double avg = 0;
	int userEnterid;

	cout << "** Netflix Movie Review Analysis **" << endl;
	cout << endl;

	cin >> fileM;
	cin >> fileR;
	
	cout << endl;

	// get file name from user
	ifstream file1(fileM);
	ifstream file2(fileR);

	
	if (!file1.good())
	{
		cout << "cannot open file!" << endl;
		return -1;
	}

	if (!file2.good())
	{
		cout << "cannot open file!" << endl;
		return -1;
	}


	// Declare vector
	vector<Movie> movie;
	vector<Review> review;


	getline(file1, line);
	
	// get data from file
	while (getline(file1, line))
	{
		stringstream ss(line);

		getline(ss, movieid, ',');
		getline(ss, moviename, ',');
		getline(ss, pubyear);

		Movie mo(stoi(movieid), moviename, stoi(pubyear), defRevi, defRati, defAvg);

		movie.push_back(mo);
		countMovie++;
	}

	getline(file2, line2);

	// get data from file
	while (getline(file2, line2))
	{

		stringstream sp(line2);

		getline(sp, reviewid, ',');
		getline(sp, movieidre, ',');
		getline(sp, useridre, ',');
		getline(sp, ratingre, ',');
		getline(sp, reviewdate);

		Review re(stoi(reviewid), stoi(movieidre), stoi(useridre), stoi(ratingre), reviewdate);
		review.push_back(re);

		countReview++;

	}


	// print total movies and reviews
	cout << ">> Reading movies... " << countMovie << endl;
	cout << ">> Reading reviews... " << countReview << endl;
	
	
	// loop to find movies and count
	for (auto &re : review)
	{
		auto iter = find_if(movie.begin(),movie.end(),[&](Movie m)
		{
			if (m.getMovieid() == re.revMoviId())
				return true;
			else
				return false;
		});

		if (iter == movie.end())
		{
			cout << "Not found" << endl;
		}

		else
			iter->setId();
			iter->setRating(re.revRating());
	}
	
	// count average of each movie
	for (auto &cu : movie)
	{
		avg = getTotalrat(cu.getRevi(), cu.totalRati());

		cu.avgRatingeach(avg);

	}

	cout << endl;
	
	cout << ">> Top-10 Movies <<" << endl << endl;

	// call function of sort vector
	sortByAvg(movie);

	
	cout << endl << ">> Movies and Review Information <<" << endl;
		

	// Build a Map for movie class
	auto M = moviemap(movie);

	// Build a Map for review class
	auto R = reviewmap(review);

	// Infinite loop
	while (true)
	{

		cout << "Please enter a movie ID(< 100,000), a review ID (>= 100,000), 0 to stop> ";
		cin >> userEnterid;

		if (userEnterid == 0)
		{
			cout << "** DONE! **" << endl;
			break;
		}

		if (userEnterid < 0)
		{
			cout << "**invalid id..." << endl;
		}
		else if (userEnterid < 100000)
		{
			lookMovieID(M, userEnterid);
		}
		else if (userEnterid >= 100000)
		{
			lookReviewID(R, userEnterid, movie);
		}

	}

	return 0;
}




"# Netflix-Analysis" 
