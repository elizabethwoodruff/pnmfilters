#include <omp.h>
#include <PNMreader.h>
#include <PNMwriter.h>
#include <filters.h>
#include <Blender.C>
#include <LRConcat.C>
#include<crop.C>
#include<transpose.C>
#include<Color.C>
#include <Checkerboard.C>
#include<CheckSum.C>
#include <invert.C>
int main(int argc, char *argv[])
{
    PNMreader reader(argv[1]);

    Crop crop;
    crop.SetRegion(300, 1400, 50, 400);
    crop.SetInput(reader.GetOutput());

    Transpose t;
    t.SetInput(crop.GetOutput());

    Invert i;
    i.SetInput(t.GetOutput());

    Color color(50, 1101, 0, 0, 128);
    
    LRConcat lr;
    lr.SetInput(color.GetOutput());
    lr.SetInput2(i.GetOutput());

    Color white(401, 1101, 255, 255, 255);

    Checkerboard cb;
    cb.SetInput(lr.GetOutput());
    cb.SetInput2(white.GetOutput());
    double serial = 0.124331 ;
    double start = omp_get_wtime();
    cb.GetOutput()->Update();
    double end = omp_get_wtime();
    double time = end - start;
    double t_diff = serial - time;
   fprintf(stdout, "time for parallel to execute: %f\n difference btw parallel and serial: %d\n", time, t_diff);
    PNMwriter writer;
    writer.SetInput(cb.GetOutput());
    writer.Write(argv[2]);

    CheckSum cs;
    cs.SetInput(cb.GetOutput());
    cs.OutputCheckSum("proj3G_checksum");
}

