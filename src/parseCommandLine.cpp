/**********************************************************************
parseCommandLine.cpp - Sieve
 
Copyright (C) 2005-2010 by Silicos NV
 
This file is part of the Open Babel project.
For more information, see <http://openbabel.sourceforge.net/>
 
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
***********************************************************************/



#include <parseCommandLine.h>
#include <cstdlib>



void
parseCommandLine(int argc, char* argv[], Options* o)
{
   static struct option Arguments[] =
	{
        { "in",              required_argument,   NULL, '1' },
		{ "pass",            required_argument,   NULL, '2' },
		{ "fail",            required_argument,   NULL, '3' },
		{ "filter",          required_argument,   NULL, '4' },
        { "salts",           no_argument,         NULL, '5' },
        { "tab",             no_argument,         NULL, '6' },
        { "noLog",           no_argument,         NULL, '7' },
        { "rename",          no_argument,         NULL, '8' },
		{ "help",            no_argument,         NULL, 'h' },
		{ "version",         no_argument,         NULL, 'v' },
      { NULL,              0,                   NULL,  0  }
	};

   // Process commandline
	int choice;
    std::string ff;
	opterr = 0;
	int optionIndex = 0;
    OpenBabel::OBFormat* format;
	while ((choice = getopt_long(argc, argv, "vh", Arguments, &optionIndex )) != -1)
	{
      switch(choice)
		{
         case 'v': 
            version();
            exit(0);
            break;

         case 'h':
            version();
            usage();
            exit(0);
            break;

         case '1':
            (void) o->InputFilename(optarg);
            format = o->InputConverter()->FormatFromExt(optarg);
            if (!format)
            {
               version();
               usage();
               std::cerr << "ERROR:" << std::endl << std::endl;
               std::cerr << "  Could not detect format from the '--in' option.\n" << std::endl;
               exit(1);
            }
            o->InputConverter()->SetInFormat(format);
            o->InputStream()->open(optarg);
            if (!o->InputStream()->good())
            {
               version();
               usage();
               std::cerr << "ERROR:" << std::endl << std::endl;
               std::cerr << "  Cannot open the file as specified by the '--in' option.\n" << std::endl;
               exit(1);
            }
            o->InputConverter()->AddOption("d", OpenBabel::OBConversion::GENOPTIONS);
            break;
            
         case '2':
            (void) o->PassFilename(optarg);
            format = o->PassConverter()->FormatFromExt(optarg);
            if (!format)
            {
               version();
               usage();
               std::cerr << "ERROR:" << std::endl << std::endl;
               std::cerr << "  Could not detect format from the '--pass' option.\n" << std::endl;
               exit(1);
            }
            o->PassConverter()->SetOutFormat(format);
            o->PassStream()->open(optarg);
            if (!o->PassStream()->good())
            {
               version();
               usage();
               std::cerr << "ERROR:" << std::endl << std::endl;
               std::cerr << "  Cannot open the file as specified by the '--pass' option.\n" << std::endl;
               exit(1);
            }
            break;

         case '3':
            (void) o->FailFilename(optarg);
            format = o->FailConverter()->FormatFromExt(optarg);
            if (!format)
            {
               version();
               usage();
               std::cerr << "ERROR:" << std::endl << std::endl;
               std::cerr << "  Could not detect format from the '--fail' option.\n" << std::endl;
               exit(1);
            }
            o->FailConverter()->SetOutFormat(format);
            o->FailStream()->open(optarg);
            if (!o->FailStream()->good())
            {
               version();
               usage();
               std::cerr << "ERROR:" << std::endl << std::endl;
               std::cerr << "  Cannot open the file as specified by the '--fail' option.\n" << std::endl;
               exit(1);
            }
            break;
            
         case '4':
            if (!o->FilterFilename(optarg))
            {
               version();
               usage();
               std::cerr << "ERROR:" << std::endl << std::endl;
               std::cerr << "  No filename provided at the '--filter' option.\n" << std::endl;
               exit(1);
            }
            break;
            
         case '5':
            o->Salts(true);
            break;
            
         case '6':
            o->Tabulate(true);
            break;
            
         case '7':
            o->NoLog(true);
            break;
            
         case '8':
            o->Rename(true);
            break;
            
			default:
            version();
            usage();
            std::cerr << "ERROR:" << std::endl << std::endl;
				std::cerr << "  Unknown command line option.\n" << std::endl;
            exit(1);
		}
	}

	argc -= optind;
	argv += optind;

   // Input file processing
   if (o->InputFilename().empty())
   {
      version();
      usage();
      std::cerr << "ERROR:" << std::endl << std::endl;
      std::cerr << "  Command line option '--in' is missing.\n" << std::endl;
      exit(1);
   }
   
   if (!o->Tabulate())
   {
      // Pass file processing
      if (o->PassFilename().empty())
      {
         version();
         usage();
         std::cerr << "ERROR:" << std::endl << std::endl;
         std::cerr << "  Command line option '--pass' is missing.\n" << std::endl;
         exit(1);
      }
   }
   
   // Filter file processing
   if (o->FilterFilename().empty())
   {
      version();
      usage();
      std::cerr << "ERROR:" << std::endl << std::endl;
      std::cerr << "  Command line option '--filter' is missing.\n" << std::endl;
      exit(1);
   }
}



void
usage(void) 
{
   std::cerr << std::endl;
   std::cerr << "TASK: " << std::endl;
   std::cerr << std::endl;
   std::cerr << "  Sieve is a tool to filter out molecules according user-defined criteria." << std::endl;
   std::cerr << std::endl;
   std::cerr << "REQUIRED OPTIONS:" << std::endl;
   std::cerr << std::endl;
   std::cerr << "  --in <file>" << std::endl;
   std::cerr << "    Specifies the file containing the input molecules. The format of the" << std::endl;
   std::cerr << "    file is specified by the file extension. Gzipped files are also read." << std::endl;
   std::cerr << std::endl;
   std::cerr << "  --pass <file>" << std::endl;
   std::cerr << "    Specifies the file to which the molecules are written that pass the filtering." << std::endl;
   std::cerr << "    The format of the file is specified by the file extension. Gzipped" << std::endl;
   std::cerr << "    files are also read." << std::endl;
   std::cerr << std::endl;
   std::cerr << "  --filter <file>" << std::endl;
   std::cerr << "    Specifies the file in which the filter criteria have been defined." << std::endl;
   std::cerr << std::endl;
   std::cerr << "OPTIONAL OPTIONS:" << std::endl;
   std::cerr << std::endl;
   std::cerr << "  --fail <file>" << std::endl;
   std::cerr << "    Specifies the file to which the molecules are written which do not" << std::endl;
   std::cerr << "    pass the filter criteria. The format of the file is specified" << std::endl;
   std::cerr << "    by the file extension. Gzipped files are also read." << std::endl;
   std::cerr << std::endl;
   std::cerr << "  --salts" << std::endl;
   std::cerr << "    This flag directs the program to keep all separate fragments instead of" << std::endl;
   std::cerr << "    stripping away all but the largest fragments before the filtering takes" << std::endl;
   std::cerr << "    place. By specifying this option, this stripping is not performed and" << std::endl;
   std::cerr << "    ensures that all salt counterions are taken into account in the filtering" << std::endl;
   std::cerr << "    process." << std::endl;
   std::cerr << std::endl;
   std::cerr << "  --rename" << std::endl;
   std::cerr << "    This flag directs the program to rename the title of each molecules" << std::endl;
   std::cerr << "    into a increasing digit reflecting the sequence of the molecule in" << std::endl;
   std::cerr << "    the input file. Existing titles are overwritten." << std::endl;
   std::cerr << std::endl;
   std::cerr << "  --tab" << std::endl;
   std::cerr << "    This flag directs the program to calculate all properties listed in" << std::endl;
   std::cerr << "    the filter definition file without applying any filtering. This option" << std::endl;
   std::cerr << "    can be used for database characterisation. The calculated parameters" << std::endl;
   std::cerr << "    are written to standard output." << std::endl;
   std::cerr << std::endl;
   std::cerr << "  --noLog" << std::endl;
   std::cerr << "    This flag specifies whether verbose logging should be switched off. If not" << std::endl;
   std::cerr << "    specified, then for each molecule a message is written to standard error" << std::endl;
   std::cerr << "    whether the molecule passes or fails the filter criteria. This behaviour" << std::endl;
   std::cerr << "    can be switched off with this command line option. However, even" << std::endl;
   std::cerr << "    when this option is specified, information is still written to standard error," << std::endl;
   std::cerr << "    but reduced to a large extend." << std::endl;
   std::cerr << std::endl;
   std::cerr << "  -h  --help" << std::endl;
   std::cerr << std::endl;
   std::cerr << "  -v  --version" << std::endl;
   std::cerr << std::endl;
}



void
version(void)
{
	std::cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cerr << "  SIEVE v" << SIEVE_VERSION << "." << SIEVE_RELEASE << "." << SIEVE_SUBRELEASE << " | ";
    std::cerr << __DATE__ " " << __TIME__ << std::endl;
	std::cerr << std::endl;
	std::cerr << "  -> GCC:         " << __VERSION__ << std::endl;
	std::cerr << "  -> Open Babel:  " << BABEL_VERSION << std::endl;
	std::cerr << std::endl;
	std::cerr << "  Copyright (C) 2005-2010 by Silicos NV" << std::endl;
	std::cerr << std::endl;
	std::cerr << "  This file is part of the Open Babel project." << std::endl;
	std::cerr << "  For more information, see <http://openbabel.sourceforge.net/>" << std::endl;
	std::cerr << std::endl;
	std::cerr << "  This program is free software; you can redistribute it and/or modify" << std::endl;
	std::cerr << "  it under the terms of the GNU General Public License as published by" << std::endl;
	std::cerr << "  the Free Software Foundation version 2 of the License." << std::endl;
	std::cerr << std::endl;
	std::cerr << "  This program is distributed in the hope that it will be useful," << std::endl;
	std::cerr << "  but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl;
	std::cerr << "  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" << std::endl;
	std::cerr << "  GNU General Public License for more details." << std::endl;
	std::cerr << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cerr << std::endl;
}

