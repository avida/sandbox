#include <iostream>

#include <assimp/cimport.h>        // Plain-C interface
#include <assimp/scene.h>          // Output data structure
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>    // Post processing flags


bool DoTheImportThing( const char* pFile)
{
  // Start the import on the given file with some example postprocessing
  // Usually - if speed is not the most important aspect for you - you'll t
  // probably to request more postprocessing than we do in this example.
  const aiScene* scene = aiImportFile( pFile, 
    aiProcess_CalcTangentSpace       | 
        aiProcess_Triangulate            |
        aiProcess_JoinIdenticalVertices  |
        aiProcess_SortByPType);
  // If the import failed, report it
  if( !scene)
  {
    return false;
  }
  // Now we can access the file's contents

  // We're done. Release all resources associated with this import
  aiReleaseImport( scene);
  return true;
}
using namespace std;

int main()
{
   Assimp::Importer Importer;

   const aiScene* pScene = Importer.ReadFile("untitled.obj", aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs);
   if (pScene) 
   {
      cout << "Meshes: " << pScene->mNumMeshes << endl;
      cout << "Materials: "<< pScene->mNumMaterials << endl;
      for (auto i=0; i < pScene->mNumMeshes; ++i)
      {
         auto mesh = pScene->mMeshes[i];
         for (auto v = 0; v < mesh->mNumVertices; ++v)
         {
             const aiVector3D* pPos      = &(mesh->mVertices[v]);
             const aiVector3D* pNormal   = &(mesh->mNormals[v]);
             cout << "{" <<pPos->x << ", " << pPos->y << ", " << pPos->z << "},"<<endl;
             // cout << "\t" << pNormal->x << " " << pNormal->y << " " << pNormal->z <<endl;
         }
         cout <<"Indices:" << endl;
         for (unsigned int in = 0 ; in < mesh->mNumFaces ; in++) {
            const aiFace& Face = mesh->mFaces[in];
            assert(Face.mNumIndices == 3);
            cout << Face.mIndices[0] << ", " << Face.mIndices[1] << ", " << Face.mIndices[2] << "," <<endl;
         }
      }
   }
    else
    {
         std::cout << "Failed to load file" << std::endl;
    } 
   return 0;
}