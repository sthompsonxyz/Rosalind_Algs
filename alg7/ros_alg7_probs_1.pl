#!/usr/bin/perl

use strict;
use warnings;

use Carp;

use List::Util qw/sum/;

my %population = ( k => 0, m => 0, n => 0);


sub select_prob {
	my ($popul, $type) = @_;

	my $total_pop = $popul->{k} + $popul->{m} + $popul->{n};
	my $probs = $popul->{$type} / $total_pop;
	if ($popul->{$type} > 0) {
		$popul->{$type}--;
		} else {
			croak "can\'t select $type, there are not enough of this kind";
		} #but what happens in populations with 0 or 1 of a type?

	return $probs;
}


sub pop_regen {
	my ($popul, $k, $m, $n) = @_;

		$popul->{k} = $k;
		$popul->{m} = $m;
		$popul->{n} = $n;


	return $popul;
}


print "amount of k (homozygous dominant):\n";

my $k = <STDIN>;
chomp $k;

print "amount of m (heterozygous):\n";

my $m = <STDIN>;
chomp $m;

print "amount of n (homozygous recessive):\n";

my $n = <STDIN>;
chomp $n;


# Create list of pair selection probabilities
my @prob_list;

foreach my $type1 (sort keys %population) {
	foreach my $type2 (sort keys %population) {
		pop_regen(\%population, $k, $m, $n);

		my $first_select = select_prob(\%population, $type1);
		my $second_select = select_prob(\%population, $type2);
		my $prob = ($first_select * $second_select);
		push @prob_list, $prob;

		printf("prob of %s with %s is %.5f\n", $type1, $type2, $prob);
	}
	print "\n";
}

# list of 9 phenotype probs for expressing dominant trait 
# corresponding to 3x3 combo pairs
# (probably a better/safer way to do this)
my @dom_phenos = (1.0, 1.0, 1.0, 1.0, 0.75, 0.5, 1.0, 0.5, 0.0);
# list of 9 phenotype probs for expressing recessive trait
# corresponding to 3x3 combo pairs
# (probably a better/safer way to do this)
my @rec_phenos = (0.0, 0.0, 0.0, 0.0, 0.25, 0.5, 0.0, 0.5, 1.0);
# note these two lists complement, the corresponding position
# of each should add to give a total prob of 1.0
my @dom_probs;
my @rec_probs;
for (my $i = 0; $i < 9; $i++) {

	push @dom_probs, ($prob_list[$i] * $dom_phenos[$i]);
	push @rec_probs, ($prob_list[$i] * $rec_phenos[$i]);

}

print "probability of getting offspring with dominant phenotype:\t\t";
print sum @dom_probs;
print "\n";

print "probability of getting offspring with recessive phenotype:\t\t";
print sum @rec_probs;
print "\n";