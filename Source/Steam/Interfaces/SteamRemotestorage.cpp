/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Steam cloudstorage.
*/

#include "../../Stdinclude.h"

#define Createmethod(Index, Class, Function)    \
auto Temp ##Function = &Class::Function;        \
Methods[Index] = *(void **)&Temp ##Function;

constexpr const char *Storagedir = "./Plugins/" MODULENAME "/Steamstorage/";

#pragma region Methods
class SteamRemotestorage
{
public:
    bool FileRead0(const char *filename, void *buffer, int size)
    {
        Printfunction();

        std::FILE *Filehandle = std::fopen(va("%s%s", Storagedir, filename).c_str(), "rb");
        if (!Filehandle) return false;

        uint8_t *pBuffer = (uint8_t *)buffer;
        while (1 != std::fread(pBuffer, 1, 1, Filehandle) && size--) pBuffer++;
        std::fclose(Filehandle);
        return true;
    }
    bool FileExists(const char *filename)
    {
        Printfunction();

        std::FILE *Filehandle = std::fopen(va("%s%s", Storagedir, filename).c_str(), "rb");
        if (!Filehandle) return false;
        std::fclose(Filehandle);
        return true;
    }
    bool FileDelete(const char *filename)
    {
        Printfunction();

        return 0 == std::remove(va("%s%s", Storagedir, filename).c_str());
    }
    const char *GetFileNameAndSize(int index, int *size)
    {
        Printfunction();

        return "";
    }
    bool GetQuota(int *current, int *maximum)
    {
        Printfunction();

        return false;
    }
    bool FileWrite(const char *pchFile, const void *pvData, int32_t cubData)
    {
        Printfunction();

        std::FILE *Filehandle = std::fopen(va("%s%s", Storagedir, pchFile).c_str(), "wb");
        if (!Filehandle) return false;

        std::fwrite(Filehandle, cubData, 1, Filehandle);
        std::fclose(Filehandle);
        return true;
    }
    int32_t GetFileSize(const char *pchFile)
    {
        Printfunction();

        int32_t Result = 0;
        std::FILE *Filehandle = std::fopen(va("%s%s", Storagedir, pchFile).c_str(), "rb");
        if (!Filehandle) return false;

        std::fseek(Filehandle, 0, SEEK_END);
        Result = std::ftell(Filehandle);
        std::fclose(Filehandle);

        return Result;
    }
    int32_t FileRead1(const char *pchFile, void *pvData, int32_t cubDataToRead)
    {
        Printfunction();

        int32_t Maxread = cubDataToRead;

        std::FILE *Filehandle = std::fopen(va("%s%s", Storagedir, pchFile).c_str(), "rb");
        if (!Filehandle) return false;

        uint8_t *pBuffer = (uint8_t *)pvData;
        while (1 != std::fread(pBuffer, 1, 1, Filehandle) && Maxread--) pBuffer++;
        std::fclose(Filehandle);

        return cubDataToRead + ~Maxread;
    }
    int32_t GetFileCount()
    {
        Printfunction();

        return 0;
    }
    bool FilePersisted(const char *pchFile)
    {
        Printfunction();

        return 0;
    }
    int64_t GetFileTimestamp(const char *pchFile)
    {
        Printfunction();

        return 0;
    }
    bool IsCloudEnabledForAccount()
    {
        Printfunction();

        return true;
    }
    bool IsCloudEnabledThisApp()
    {
        Printfunction();

        return true;
    }
    bool SetCloudEnabledThisApp(bool bEnable)
    {
        Printfunction();

        return true;
    }
    uint64_t UGCDownload0(uint32_t hContent)
    {
        Printfunction();

        return 0;
    }
    bool GetUGCDetails(uint32_t hContent, uint32_t *pnAppID, char **ppchName, int32_t *pnFileSizeInBytes, CSteamID *pSteamIDOwner)
    {
        Printfunction();

        return 0;
    }
    int32_t UGCRead0(uint32_t hContent, void *pvData, int32_t cubDataToRead)
    {
        Printfunction();

        return 0;
    }
    int32_t GetCachedUGCCount()
    {
        Printfunction();

        return 0;
    }
    uint32_t GetCachedUGCHandle(int32_t iCachedContent)
    {
        Printfunction();

        return 0;
    }
    bool SetSyncPlatforms(const char *pchFile, uint32_t eRemoteStoragePlatform)
    {
        Printfunction();

        return true;
    }
    uint32_t GetSyncPlatforms(const char *pchFile)
    {
        Printfunction();

        return 0xFFFFFFFF;
    }
    bool IsCloudEnabledForApp()
    {
        Printfunction();

        return 0;
    }
    void SetCloudEnabledForApp(bool bEnabled)
    {
        Printfunction();

        return;
    }
    uint64_t PublishFile(const char *pchFile, const char *pchPreviewFile, uint32_t nConsumerAppId, const char *pchTitle, const char *pchDescription, uint32_t eVisibility, struct SteamParamStringArray_t *pTags)
    {
        Printfunction();

        return 0;
    }
    uint64_t PublishWorkshopFile0(const char *pchFile, const char *pchPreviewFile, uint32_t nConsumerAppId, const char *pchTitle, const char *pchDescription, struct SteamParamStringArray_t *pTags)
    {
        Printfunction();

        return 0;
    }
    uint64_t UpdatePublishedFile(uint32_t updatePublishedFileRequest)
    {
        Printfunction();

        return 0;
    }
    uint64_t GetPublishedFileDetails0(uint32_t unPublishedFileId)
    {
        Printfunction();

        return 0;
    }
    uint64_t DeletePublishedFile(uint32_t unPublishedFileId)
    {
        Printfunction();

        return 0;
    }
    uint64_t EnumerateUserPublishedFiles(uint32_t unStartIndex)
    {
        Printfunction();

        return 0;
    }
    uint64_t SubscribePublishedFile(uint32_t unPublishedFileId)
    {
        Printfunction();

        return 0;
    }
    uint64_t EnumerateUserSubscribedFiles(uint32_t unStartIndex)
    {
        Printfunction();

        return 0;
    }
    uint64_t UnsubscribePublishedFile(uint32_t unPublishedFileId)
    {
        Printfunction();

        return 0;
    }
    bool GetUGCDownloadProgress(uint32_t hContent, uint32_t *puDownloadedBytes, uint32_t *puTotalBytes)
    {
        Printfunction();

        return 0;
    }
    uint64_t PublishWorkshopFile1(const char *pchFile, const char *pchPreviewFile, uint32_t nConsumerAppId, const char *pchTitle, const char *pchDescription, uint32_t eVisibility, struct SteamParamStringArray_t *pTags, uint32_t eWorkshopFileType)
    {
        Printfunction();

        return 0;
    }
    uint64_t CreatePublishedFileUpdateRequest(uint32_t unPublishedFileId)
    {
        Printfunction();

        return 0;
    }
    bool UpdatePublishedFileFile(uint64_t hUpdateRequest, const char *pchFile)
    {
        Printfunction();

        return 0;
    }
    bool UpdatePublishedFilePreviewFile(uint64_t hUpdateRequest, const char *pchPreviewFile)
    {
        Printfunction();

        return 0;
    }
    bool UpdatePublishedFileTitle(uint64_t hUpdateRequest, const char *pchTitle)
    {
        Printfunction();

        return 0;
    }
    bool UpdatePublishedFileDescription(uint64_t hUpdateRequest, const char *pchDescription)
    {
        Printfunction();

        return 0;
    }
    bool UpdatePublishedFileVisibility(uint64_t hUpdateRequest, uint32_t eVisibility)
    {
        Printfunction();

        return 0;
    }
    bool UpdatePublishedFileTags(uint64_t hUpdateRequest, struct SteamParamStringArray_t *pTags)
    {
        Printfunction();

        return 0;
    }
    uint64_t CommitPublishedFileUpdate(uint64_t hUpdateRequest)
    {
        Printfunction();

        return 0;
    }
    bool UpdatePublishedFileSetChangeDescription(uint64_t hUpdateRequest, const char *cszDescription)
    {
        Printfunction();

        return 0;
    }
    uint64_t GetPublishedItemVoteDetails(uint32_t unPublishedFileId)
    {
        Printfunction();

        return 0;
    }
    uint64_t UpdateUserPublishedItemVote(uint32_t unPublishedFileId, bool bVoteUp)
    {
        Printfunction();

        return 0;
    }
    uint64_t GetUserPublishedItemVoteDetails(uint32_t unPublishedFileId)
    {
        Printfunction();

        return 0;
    }
    uint64_t EnumerateUserSharedWorkshopFiles(uint32_t nAppId, CSteamID creatorSteamID, uint32_t uStartIndex, struct SteamParamStringArray_t * pRequiredTags, struct SteamParamStringArray_t * pExcludedTags)
    {
        Printfunction();

        return 0;
    }
    uint64_t PublishVideo0(const char *cszFileName, const char *cszPreviewFileName, uint32_t nConsumerAppId, const char *cszTitle, const char *cszDescription, uint32_t eVisibility, struct SteamParamStringArray_t *pTags)
    {
        Printfunction();

        return 0;
    }
    uint64_t SetUserPublishedFileAction(uint32_t unPublishedFileId, uint32_t eAction)
    {
        Printfunction();

        return 0;
    }
    uint64_t EnumeratePublishedFilesByUserAction(uint32_t eAction, uint32_t uStartIndex)
    {
        Printfunction();

        return 0;
    }
    uint64_t EnumeratePublishedWorkshopFiles(uint32_t eType, uint32_t uStartIndex, uint32_t cDays, uint32_t cCount, struct SteamParamStringArray_t *pTags, struct SteamParamStringArray_t *pUserTags)
    {
        Printfunction();

        return 0;
    }
    uint64_t PublishVideo1(uint32_t eVideoProvider, const char *cszVideoAccountName, const char *cszVideoIdentifier, const char *cszFileName, uint32_t nConsumerAppId, const char *cszTitle, const char *cszDescription, uint32_t eVisibility, struct SteamParamStringArray_t *pTags)
    {
        Printfunction();

        return 0;
    }
    uint64_t FileWriteStreamOpen(const char *pchFile)
    {
        Printfunction();

        return 0;
    }
    EResult FileWriteStreamWriteChunk(uint64_t hStream, const void *pvData, int32_t cubData)
    {
        Printfunction();

        return EResult::k_EResultOK;
    }
    EResult FileWriteStreamClose(uint64_t hStream)
    {
        Printfunction();

        return EResult::k_EResultOK;
    }
    EResult FileWriteStreamCancel(uint64_t hStream)
    {
        Printfunction();

        return EResult::k_EResultOK;
    }
    int32_t UGCRead1(uint32_t hContent, void *pvData, int32_t cubDataToRead, uint32_t uOffset)
    {
        Printfunction();

        return 0;
    }
    uint64_t UGCDownload1(uint32_t hContent, uint32_t uUnk)
    {
        Printfunction();

        return 0;
    }
    uint64_t UGCDownloadToLocation(uint32_t hContent, const char *cszLocation, uint32_t uUnk)
    {
        Printfunction();

        return 0;
    }
    uint64_t GetPublishedFileDetails1(uint32_t unPublishedFileId, uint32_t)
    {
        Printfunction();

        return 0;
    }
    int32_t UGCRead2(uint32_t hContent, void *pvData, int32_t cubDataToRead, uint32_t uOffset, uint32_t eAction)
    {
        Printfunction();

        return 0;
    }

    bool FileForget(const char *pchFile)
    {
        Printfunction();

        return true;
    }
    uint64_t FileShare(const char *pchFile)
    {
        Printfunction();

        return 0;
    }
    uint64_t UGCDownload(uint32_t hContent)
    {
        Printfunction();

        return 0;
    }

};
#pragma endregion

SteamRemotestorage001::SteamRemotestorage001()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, GetFileSize);
    Createmethod(2, SteamRemotestorage, FileRead0);
    Createmethod(3, SteamRemotestorage, FileExists);
    Createmethod(4, SteamRemotestorage, FileDelete);
    Createmethod(5, SteamRemotestorage, GetFileCount);
    Createmethod(6, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(7, SteamRemotestorage, GetQuota);
};
SteamRemotestorage002::SteamRemotestorage002()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, GetFileSize);
    Createmethod(2, SteamRemotestorage, FileRead1);
    Createmethod(3, SteamRemotestorage, FileExists);
    Createmethod(4, SteamRemotestorage, GetFileCount);
    Createmethod(5, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(6, SteamRemotestorage, GetQuota);
};
SteamRemotestorage003::SteamRemotestorage003()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, FileRead1);
    Createmethod(2, SteamRemotestorage, FileForget);
    Createmethod(3, SteamRemotestorage, FileDelete);
    Createmethod(4, SteamRemotestorage, FileShare);
    Createmethod(5, SteamRemotestorage, FileExists);
    Createmethod(6, SteamRemotestorage, FilePersisted);
    Createmethod(7, SteamRemotestorage, GetFileSize);
    Createmethod(8, SteamRemotestorage, GetFileTimestamp);
    Createmethod(9, SteamRemotestorage, GetFileCount);
    Createmethod(10, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(11, SteamRemotestorage, GetQuota);
    Createmethod(12, SteamRemotestorage, IsCloudEnabledForAccount);
    Createmethod(13, SteamRemotestorage, IsCloudEnabledThisApp);
    Createmethod(14, SteamRemotestorage, SetCloudEnabledThisApp);
    Createmethod(15, SteamRemotestorage, UGCDownload0);
    Createmethod(16, SteamRemotestorage, GetUGCDetails);
    Createmethod(17, SteamRemotestorage, UGCRead0);
    Createmethod(18, SteamRemotestorage, GetCachedUGCCount);
    Createmethod(19, SteamRemotestorage, GetCachedUGCHandle);
};
SteamRemotestorage004::SteamRemotestorage004()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, FileRead1);
    Createmethod(2, SteamRemotestorage, FileForget);
    Createmethod(3, SteamRemotestorage, FileDelete);
    Createmethod(4, SteamRemotestorage, FileShare);
    Createmethod(5, SteamRemotestorage, SetSyncPlatforms);
    Createmethod(6, SteamRemotestorage, FileExists);
    Createmethod(7, SteamRemotestorage, FilePersisted);
    Createmethod(8, SteamRemotestorage, GetFileSize);
    Createmethod(9, SteamRemotestorage, GetFileTimestamp);
    Createmethod(10, SteamRemotestorage, GetSyncPlatforms);
    Createmethod(11, SteamRemotestorage, GetFileCount);
    Createmethod(12, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(13, SteamRemotestorage, GetQuota);
    Createmethod(14, SteamRemotestorage, IsCloudEnabledForAccount);
    Createmethod(15, SteamRemotestorage, IsCloudEnabledForApp);
    Createmethod(16, SteamRemotestorage, SetCloudEnabledForApp);
    Createmethod(17, SteamRemotestorage, UGCDownload);
    Createmethod(18, SteamRemotestorage, GetUGCDetails);
    Createmethod(19, SteamRemotestorage, UGCRead0);
    Createmethod(20, SteamRemotestorage, GetCachedUGCCount);
    Createmethod(21, SteamRemotestorage, GetCachedUGCHandle);
};
SteamRemotestorage005::SteamRemotestorage005()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, FileRead1);
    Createmethod(2, SteamRemotestorage, FileForget);
    Createmethod(3, SteamRemotestorage, FileDelete);
    Createmethod(4, SteamRemotestorage, FileShare);
    Createmethod(5, SteamRemotestorage, SetSyncPlatforms);
    Createmethod(6, SteamRemotestorage, FileExists);
    Createmethod(7, SteamRemotestorage, FilePersisted);
    Createmethod(8, SteamRemotestorage, GetFileSize);
    Createmethod(9, SteamRemotestorage, GetFileTimestamp);
    Createmethod(10, SteamRemotestorage, GetSyncPlatforms);
    Createmethod(11, SteamRemotestorage, GetFileCount);
    Createmethod(12, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(13, SteamRemotestorage, GetQuota);
    Createmethod(14, SteamRemotestorage, IsCloudEnabledForAccount);
    Createmethod(15, SteamRemotestorage, IsCloudEnabledForApp);
    Createmethod(16, SteamRemotestorage, SetCloudEnabledForApp);
    Createmethod(17, SteamRemotestorage, UGCDownload);
    Createmethod(18, SteamRemotestorage, GetUGCDetails);
    Createmethod(19, SteamRemotestorage, UGCRead0);
    Createmethod(20, SteamRemotestorage, GetCachedUGCCount);
    Createmethod(21, SteamRemotestorage, GetCachedUGCHandle);
    Createmethod(22, SteamRemotestorage, PublishFile);
    Createmethod(23, SteamRemotestorage, PublishWorkshopFile0);
    Createmethod(24, SteamRemotestorage, UpdatePublishedFile);
    Createmethod(25, SteamRemotestorage, GetPublishedFileDetails0);
    Createmethod(26, SteamRemotestorage, DeletePublishedFile);
    Createmethod(27, SteamRemotestorage, EnumerateUserPublishedFiles);
    Createmethod(28, SteamRemotestorage, SubscribePublishedFile);
    Createmethod(29, SteamRemotestorage, EnumerateUserSubscribedFiles);
    Createmethod(30, SteamRemotestorage, UnsubscribePublishedFile);
};
SteamRemotestorage006::SteamRemotestorage006()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, FileRead1);
    Createmethod(2, SteamRemotestorage, FileForget);
    Createmethod(3, SteamRemotestorage, FileDelete);
    Createmethod(4, SteamRemotestorage, FileShare);
    Createmethod(5, SteamRemotestorage, SetSyncPlatforms);
    Createmethod(6, SteamRemotestorage, FileExists);
    Createmethod(7, SteamRemotestorage, FilePersisted);
    Createmethod(8, SteamRemotestorage, GetFileSize);
    Createmethod(9, SteamRemotestorage, GetFileTimestamp);
    Createmethod(10, SteamRemotestorage, GetSyncPlatforms);
    Createmethod(11, SteamRemotestorage, GetFileCount);
    Createmethod(12, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(13, SteamRemotestorage, GetQuota);
    Createmethod(14, SteamRemotestorage, IsCloudEnabledForAccount);
    Createmethod(15, SteamRemotestorage, IsCloudEnabledForApp);
    Createmethod(16, SteamRemotestorage, SetCloudEnabledForApp);
    Createmethod(17, SteamRemotestorage, UGCDownload);
    Createmethod(18, SteamRemotestorage, GetUGCDownloadProgress);
    Createmethod(19, SteamRemotestorage, GetUGCDetails);
    Createmethod(20, SteamRemotestorage, UGCRead0);
    Createmethod(21, SteamRemotestorage, GetCachedUGCCount);
    Createmethod(22, SteamRemotestorage, GetCachedUGCHandle);
    Createmethod(23, SteamRemotestorage, PublishWorkshopFile1);
    Createmethod(24, SteamRemotestorage, CreatePublishedFileUpdateRequest);
    Createmethod(25, SteamRemotestorage, UpdatePublishedFileFile);
    Createmethod(26, SteamRemotestorage, UpdatePublishedFilePreviewFile);
    Createmethod(27, SteamRemotestorage, UpdatePublishedFileTitle);
    Createmethod(28, SteamRemotestorage, UpdatePublishedFileDescription);
    Createmethod(29, SteamRemotestorage, UpdatePublishedFileVisibility);
    Createmethod(30, SteamRemotestorage, UpdatePublishedFileTags);
    Createmethod(31, SteamRemotestorage, CommitPublishedFileUpdate);
    Createmethod(32, SteamRemotestorage, GetPublishedFileDetails0);
    Createmethod(33, SteamRemotestorage, DeletePublishedFile);
    Createmethod(34, SteamRemotestorage, EnumerateUserPublishedFiles);
    Createmethod(35, SteamRemotestorage, SubscribePublishedFile);
    Createmethod(36, SteamRemotestorage, EnumerateUserSubscribedFiles);
    Createmethod(37, SteamRemotestorage, UnsubscribePublishedFile);
    Createmethod(38, SteamRemotestorage, UpdatePublishedFileSetChangeDescription);
    Createmethod(39, SteamRemotestorage, GetPublishedItemVoteDetails);
    Createmethod(40, SteamRemotestorage, UpdateUserPublishedItemVote);
    Createmethod(41, SteamRemotestorage, GetUserPublishedItemVoteDetails);
    Createmethod(42, SteamRemotestorage, EnumerateUserSharedWorkshopFiles);
    Createmethod(43, SteamRemotestorage, PublishVideo0);
    Createmethod(44, SteamRemotestorage, SetUserPublishedFileAction);
    Createmethod(45, SteamRemotestorage, EnumeratePublishedFilesByUserAction);
    Createmethod(46, SteamRemotestorage, EnumeratePublishedWorkshopFiles);
};
SteamRemotestorage007::SteamRemotestorage007()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, FileRead1);
    Createmethod(2, SteamRemotestorage, FileForget);
    Createmethod(3, SteamRemotestorage, FileDelete);
    Createmethod(4, SteamRemotestorage, FileShare);
    Createmethod(5, SteamRemotestorage, SetSyncPlatforms);
    Createmethod(6, SteamRemotestorage, FileExists);
    Createmethod(7, SteamRemotestorage, FilePersisted);
    Createmethod(8, SteamRemotestorage, GetFileSize);
    Createmethod(9, SteamRemotestorage, GetFileTimestamp);
    Createmethod(10, SteamRemotestorage, GetSyncPlatforms);
    Createmethod(11, SteamRemotestorage, GetFileCount);
    Createmethod(12, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(13, SteamRemotestorage, GetQuota);
    Createmethod(14, SteamRemotestorage, IsCloudEnabledForAccount);
    Createmethod(15, SteamRemotestorage, IsCloudEnabledForApp);
    Createmethod(16, SteamRemotestorage, SetCloudEnabledForApp);
    Createmethod(17, SteamRemotestorage, UGCDownload);
    Createmethod(18, SteamRemotestorage, GetUGCDownloadProgress);
    Createmethod(19, SteamRemotestorage, GetUGCDetails);
    Createmethod(20, SteamRemotestorage, UGCRead0);
    Createmethod(21, SteamRemotestorage, GetCachedUGCCount);
    Createmethod(22, SteamRemotestorage, GetCachedUGCHandle);
    Createmethod(23, SteamRemotestorage, PublishWorkshopFile1);
    Createmethod(24, SteamRemotestorage, CreatePublishedFileUpdateRequest);
    Createmethod(25, SteamRemotestorage, UpdatePublishedFileFile);
    Createmethod(26, SteamRemotestorage, UpdatePublishedFilePreviewFile);
    Createmethod(27, SteamRemotestorage, UpdatePublishedFileTitle);
    Createmethod(28, SteamRemotestorage, UpdatePublishedFileDescription);
    Createmethod(29, SteamRemotestorage, UpdatePublishedFileVisibility);
    Createmethod(30, SteamRemotestorage, UpdatePublishedFileTags);
    Createmethod(31, SteamRemotestorage, CommitPublishedFileUpdate);
    Createmethod(32, SteamRemotestorage, GetPublishedFileDetails0);
    Createmethod(33, SteamRemotestorage, DeletePublishedFile);
    Createmethod(34, SteamRemotestorage, EnumerateUserPublishedFiles);
    Createmethod(35, SteamRemotestorage, SubscribePublishedFile);
    Createmethod(36, SteamRemotestorage, EnumerateUserSubscribedFiles);
    Createmethod(37, SteamRemotestorage, UnsubscribePublishedFile);
    Createmethod(38, SteamRemotestorage, UpdatePublishedFileSetChangeDescription);
    Createmethod(39, SteamRemotestorage, GetPublishedItemVoteDetails);
    Createmethod(40, SteamRemotestorage, UpdateUserPublishedItemVote);
    Createmethod(41, SteamRemotestorage, GetUserPublishedItemVoteDetails);
    Createmethod(42, SteamRemotestorage, EnumerateUserSharedWorkshopFiles);
    Createmethod(43, SteamRemotestorage, PublishVideo1);
    Createmethod(44, SteamRemotestorage, SetUserPublishedFileAction);
    Createmethod(45, SteamRemotestorage, EnumeratePublishedFilesByUserAction);
    Createmethod(46, SteamRemotestorage, EnumeratePublishedWorkshopFiles);
};
SteamRemotestorage008::SteamRemotestorage008()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, FileRead1);
    Createmethod(2, SteamRemotestorage, FileForget);
    Createmethod(3, SteamRemotestorage, FileDelete);
    Createmethod(4, SteamRemotestorage, FileShare);
    Createmethod(5, SteamRemotestorage, SetSyncPlatforms);
    Createmethod(6, SteamRemotestorage, FileWriteStreamOpen);
    Createmethod(7, SteamRemotestorage, FileWriteStreamWriteChunk);
    Createmethod(8, SteamRemotestorage, FileWriteStreamClose);
    Createmethod(9, SteamRemotestorage, FileWriteStreamCancel);
    Createmethod(10, SteamRemotestorage, FileExists);
    Createmethod(11, SteamRemotestorage, FilePersisted);
    Createmethod(12, SteamRemotestorage, GetFileSize);
    Createmethod(13, SteamRemotestorage, GetFileTimestamp);
    Createmethod(14, SteamRemotestorage, GetSyncPlatforms);
    Createmethod(15, SteamRemotestorage, GetFileCount);
    Createmethod(16, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(17, SteamRemotestorage, GetQuota);
    Createmethod(18, SteamRemotestorage, IsCloudEnabledForAccount);
    Createmethod(19, SteamRemotestorage, IsCloudEnabledForApp);
    Createmethod(20, SteamRemotestorage, SetCloudEnabledForApp);
    Createmethod(21, SteamRemotestorage, UGCDownload);
    Createmethod(22, SteamRemotestorage, GetUGCDownloadProgress);
    Createmethod(23, SteamRemotestorage, GetUGCDetails);
    Createmethod(24, SteamRemotestorage, UGCRead0);
    Createmethod(25, SteamRemotestorage, GetCachedUGCCount);
    Createmethod(26, SteamRemotestorage, GetCachedUGCHandle);
    Createmethod(27, SteamRemotestorage, PublishWorkshopFile1);
    Createmethod(28, SteamRemotestorage, CreatePublishedFileUpdateRequest);
    Createmethod(29, SteamRemotestorage, UpdatePublishedFileFile);
    Createmethod(30, SteamRemotestorage, UpdatePublishedFilePreviewFile);
    Createmethod(31, SteamRemotestorage, UpdatePublishedFileTitle);
    Createmethod(32, SteamRemotestorage, UpdatePublishedFileDescription);
    Createmethod(33, SteamRemotestorage, UpdatePublishedFileVisibility);
    Createmethod(34, SteamRemotestorage, UpdatePublishedFileTags);
    Createmethod(35, SteamRemotestorage, CommitPublishedFileUpdate);
    Createmethod(36, SteamRemotestorage, GetPublishedFileDetails0);
    Createmethod(37, SteamRemotestorage, DeletePublishedFile);
    Createmethod(38, SteamRemotestorage, EnumerateUserPublishedFiles);
    Createmethod(39, SteamRemotestorage, SubscribePublishedFile);
    Createmethod(40, SteamRemotestorage, EnumerateUserSubscribedFiles);
    Createmethod(41, SteamRemotestorage, UnsubscribePublishedFile);
    Createmethod(42, SteamRemotestorage, UpdatePublishedFileSetChangeDescription);
    Createmethod(43, SteamRemotestorage, GetPublishedItemVoteDetails);
    Createmethod(44, SteamRemotestorage, UpdateUserPublishedItemVote);
    Createmethod(45, SteamRemotestorage, GetUserPublishedItemVoteDetails);
    Createmethod(46, SteamRemotestorage, EnumerateUserSharedWorkshopFiles);
    Createmethod(47, SteamRemotestorage, PublishVideo1);
    Createmethod(48, SteamRemotestorage, SetUserPublishedFileAction);
    Createmethod(49, SteamRemotestorage, EnumeratePublishedFilesByUserAction);
    Createmethod(50, SteamRemotestorage, EnumeratePublishedWorkshopFiles);
};
SteamRemotestorage009::SteamRemotestorage009()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, FileRead1);
    Createmethod(2, SteamRemotestorage, FileForget);
    Createmethod(3, SteamRemotestorage, FileDelete);
    Createmethod(4, SteamRemotestorage, FileShare);
    Createmethod(5, SteamRemotestorage, SetSyncPlatforms);
    Createmethod(6, SteamRemotestorage, FileWriteStreamOpen);
    Createmethod(7, SteamRemotestorage, FileWriteStreamWriteChunk);
    Createmethod(8, SteamRemotestorage, FileWriteStreamClose);
    Createmethod(9, SteamRemotestorage, FileWriteStreamCancel);
    Createmethod(10, SteamRemotestorage, FileExists);
    Createmethod(11, SteamRemotestorage, FilePersisted);
    Createmethod(12, SteamRemotestorage, GetFileSize);
    Createmethod(13, SteamRemotestorage, GetFileTimestamp);
    Createmethod(14, SteamRemotestorage, GetSyncPlatforms);
    Createmethod(15, SteamRemotestorage, GetFileCount);
    Createmethod(16, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(17, SteamRemotestorage, GetQuota);
    Createmethod(18, SteamRemotestorage, IsCloudEnabledForAccount);
    Createmethod(19, SteamRemotestorage, IsCloudEnabledForApp);
    Createmethod(20, SteamRemotestorage, SetCloudEnabledForApp);
    Createmethod(21, SteamRemotestorage, UGCDownload);
    Createmethod(22, SteamRemotestorage, GetUGCDownloadProgress);
    Createmethod(23, SteamRemotestorage, GetUGCDetails);
    Createmethod(24, SteamRemotestorage, UGCRead1);
    Createmethod(25, SteamRemotestorage, GetCachedUGCCount);
    Createmethod(26, SteamRemotestorage, GetCachedUGCHandle);
    Createmethod(27, SteamRemotestorage, PublishWorkshopFile1);
    Createmethod(28, SteamRemotestorage, CreatePublishedFileUpdateRequest);
    Createmethod(29, SteamRemotestorage, UpdatePublishedFileFile);
    Createmethod(30, SteamRemotestorage, UpdatePublishedFilePreviewFile);
    Createmethod(31, SteamRemotestorage, UpdatePublishedFileTitle);
    Createmethod(32, SteamRemotestorage, UpdatePublishedFileDescription);
    Createmethod(33, SteamRemotestorage, UpdatePublishedFileVisibility);
    Createmethod(34, SteamRemotestorage, UpdatePublishedFileTags);
    Createmethod(35, SteamRemotestorage, CommitPublishedFileUpdate);
    Createmethod(36, SteamRemotestorage, GetPublishedFileDetails0);
    Createmethod(37, SteamRemotestorage, DeletePublishedFile);
    Createmethod(38, SteamRemotestorage, EnumerateUserPublishedFiles);
    Createmethod(39, SteamRemotestorage, SubscribePublishedFile);
    Createmethod(40, SteamRemotestorage, EnumerateUserSubscribedFiles);
    Createmethod(41, SteamRemotestorage, UnsubscribePublishedFile);
    Createmethod(42, SteamRemotestorage, UpdatePublishedFileSetChangeDescription);
    Createmethod(43, SteamRemotestorage, GetPublishedItemVoteDetails);
    Createmethod(44, SteamRemotestorage, UpdateUserPublishedItemVote);
    Createmethod(45, SteamRemotestorage, GetUserPublishedItemVoteDetails);
    Createmethod(46, SteamRemotestorage, EnumerateUserSharedWorkshopFiles);
    Createmethod(47, SteamRemotestorage, PublishVideo1);
    Createmethod(48, SteamRemotestorage, SetUserPublishedFileAction);
    Createmethod(49, SteamRemotestorage, EnumeratePublishedFilesByUserAction);
    Createmethod(50, SteamRemotestorage, EnumeratePublishedWorkshopFiles);
};
SteamRemotestorage010::SteamRemotestorage010()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, FileRead1);
    Createmethod(2, SteamRemotestorage, FileForget);
    Createmethod(3, SteamRemotestorage, FileDelete);
    Createmethod(4, SteamRemotestorage, FileShare);
    Createmethod(5, SteamRemotestorage, SetSyncPlatforms);
    Createmethod(6, SteamRemotestorage, FileWriteStreamOpen);
    Createmethod(7, SteamRemotestorage, FileWriteStreamWriteChunk);
    Createmethod(8, SteamRemotestorage, FileWriteStreamClose);
    Createmethod(9, SteamRemotestorage, FileWriteStreamCancel);
    Createmethod(10, SteamRemotestorage, FileExists);
    Createmethod(11, SteamRemotestorage, FilePersisted);
    Createmethod(12, SteamRemotestorage, GetFileSize);
    Createmethod(13, SteamRemotestorage, GetFileTimestamp);
    Createmethod(14, SteamRemotestorage, GetSyncPlatforms);
    Createmethod(15, SteamRemotestorage, GetFileCount);
    Createmethod(16, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(17, SteamRemotestorage, GetQuota);
    Createmethod(18, SteamRemotestorage, IsCloudEnabledForAccount);
    Createmethod(19, SteamRemotestorage, IsCloudEnabledForApp);
    Createmethod(20, SteamRemotestorage, SetCloudEnabledForApp);
    Createmethod(21, SteamRemotestorage, UGCDownload);
    Createmethod(22, SteamRemotestorage, GetUGCDownloadProgress);
    Createmethod(23, SteamRemotestorage, GetUGCDetails);
    Createmethod(24, SteamRemotestorage, UGCRead1);
    Createmethod(25, SteamRemotestorage, GetCachedUGCCount);
    Createmethod(26, SteamRemotestorage, GetCachedUGCHandle);
    Createmethod(27, SteamRemotestorage, PublishWorkshopFile1);
    Createmethod(28, SteamRemotestorage, CreatePublishedFileUpdateRequest);
    Createmethod(29, SteamRemotestorage, UpdatePublishedFileFile);
    Createmethod(30, SteamRemotestorage, UpdatePublishedFilePreviewFile);
    Createmethod(31, SteamRemotestorage, UpdatePublishedFileTitle);
    Createmethod(32, SteamRemotestorage, UpdatePublishedFileDescription);
    Createmethod(33, SteamRemotestorage, UpdatePublishedFileVisibility);
    Createmethod(34, SteamRemotestorage, UpdatePublishedFileTags);
    Createmethod(35, SteamRemotestorage, CommitPublishedFileUpdate);
    Createmethod(36, SteamRemotestorage, GetPublishedFileDetails0);
    Createmethod(37, SteamRemotestorage, DeletePublishedFile);
    Createmethod(38, SteamRemotestorage, EnumerateUserPublishedFiles);
    Createmethod(39, SteamRemotestorage, SubscribePublishedFile);
    Createmethod(40, SteamRemotestorage, EnumerateUserSubscribedFiles);
    Createmethod(41, SteamRemotestorage, UnsubscribePublishedFile);
    Createmethod(42, SteamRemotestorage, UpdatePublishedFileSetChangeDescription);
    Createmethod(43, SteamRemotestorage, GetPublishedItemVoteDetails);
    Createmethod(44, SteamRemotestorage, UpdateUserPublishedItemVote);
    Createmethod(45, SteamRemotestorage, GetUserPublishedItemVoteDetails);
    Createmethod(46, SteamRemotestorage, EnumerateUserSharedWorkshopFiles);
    Createmethod(47, SteamRemotestorage, PublishVideo1);
    Createmethod(48, SteamRemotestorage, SetUserPublishedFileAction);
    Createmethod(49, SteamRemotestorage, EnumeratePublishedFilesByUserAction);
    Createmethod(50, SteamRemotestorage, EnumeratePublishedWorkshopFiles);
    Createmethod(51, SteamRemotestorage, UGCDownloadToLocation);
};
SteamRemotestorage011::SteamRemotestorage011()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, FileRead1);
    Createmethod(2, SteamRemotestorage, FileForget);
    Createmethod(3, SteamRemotestorage, FileDelete);
    Createmethod(4, SteamRemotestorage, FileShare);
    Createmethod(5, SteamRemotestorage, SetSyncPlatforms);
    Createmethod(6, SteamRemotestorage, FileWriteStreamOpen);
    Createmethod(7, SteamRemotestorage, FileWriteStreamWriteChunk);
    Createmethod(8, SteamRemotestorage, FileWriteStreamClose);
    Createmethod(9, SteamRemotestorage, FileWriteStreamCancel);
    Createmethod(10, SteamRemotestorage, FileExists);
    Createmethod(11, SteamRemotestorage, FilePersisted);
    Createmethod(12, SteamRemotestorage, GetFileSize);
    Createmethod(13, SteamRemotestorage, GetFileTimestamp);
    Createmethod(14, SteamRemotestorage, GetSyncPlatforms);
    Createmethod(15, SteamRemotestorage, GetFileCount);
    Createmethod(16, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(17, SteamRemotestorage, GetQuota);
    Createmethod(18, SteamRemotestorage, IsCloudEnabledForAccount);
    Createmethod(19, SteamRemotestorage, IsCloudEnabledForApp);
    Createmethod(20, SteamRemotestorage, SetCloudEnabledForApp);
    Createmethod(21, SteamRemotestorage, UGCDownload);
    Createmethod(22, SteamRemotestorage, GetUGCDownloadProgress);
    Createmethod(23, SteamRemotestorage, GetUGCDetails);
    Createmethod(24, SteamRemotestorage, UGCRead1);
    Createmethod(25, SteamRemotestorage, GetCachedUGCCount);
    Createmethod(26, SteamRemotestorage, GetCachedUGCHandle);
    Createmethod(27, SteamRemotestorage, PublishWorkshopFile1);
    Createmethod(28, SteamRemotestorage, CreatePublishedFileUpdateRequest);
    Createmethod(29, SteamRemotestorage, UpdatePublishedFileFile);
    Createmethod(30, SteamRemotestorage, UpdatePublishedFilePreviewFile);
    Createmethod(31, SteamRemotestorage, UpdatePublishedFileTitle);
    Createmethod(32, SteamRemotestorage, UpdatePublishedFileDescription);
    Createmethod(33, SteamRemotestorage, UpdatePublishedFileVisibility);
    Createmethod(34, SteamRemotestorage, UpdatePublishedFileTags);
    Createmethod(35, SteamRemotestorage, CommitPublishedFileUpdate);
    Createmethod(36, SteamRemotestorage, GetPublishedFileDetails1);
    Createmethod(37, SteamRemotestorage, DeletePublishedFile);
    Createmethod(38, SteamRemotestorage, EnumerateUserPublishedFiles);
    Createmethod(39, SteamRemotestorage, SubscribePublishedFile);
    Createmethod(40, SteamRemotestorage, EnumerateUserSubscribedFiles);
    Createmethod(41, SteamRemotestorage, UnsubscribePublishedFile);
    Createmethod(42, SteamRemotestorage, UpdatePublishedFileSetChangeDescription);
    Createmethod(43, SteamRemotestorage, GetPublishedItemVoteDetails);
    Createmethod(44, SteamRemotestorage, UpdateUserPublishedItemVote);
    Createmethod(45, SteamRemotestorage, GetUserPublishedItemVoteDetails);
    Createmethod(46, SteamRemotestorage, EnumerateUserSharedWorkshopFiles);
    Createmethod(47, SteamRemotestorage, PublishVideo1);
    Createmethod(48, SteamRemotestorage, SetUserPublishedFileAction);
    Createmethod(49, SteamRemotestorage, EnumeratePublishedFilesByUserAction);
    Createmethod(50, SteamRemotestorage, EnumeratePublishedWorkshopFiles);
    Createmethod(51, SteamRemotestorage, UGCDownloadToLocation);
};
SteamRemotestorage012::SteamRemotestorage012()
{
    Createmethod(0, SteamRemotestorage, FileWrite);
    Createmethod(1, SteamRemotestorage, FileRead1);
    Createmethod(2, SteamRemotestorage, FileForget);
    Createmethod(3, SteamRemotestorage, FileDelete);
    Createmethod(4, SteamRemotestorage, FileShare);
    Createmethod(5, SteamRemotestorage, SetSyncPlatforms);
    Createmethod(6, SteamRemotestorage, FileWriteStreamOpen);
    Createmethod(7, SteamRemotestorage, FileWriteStreamWriteChunk);
    Createmethod(8, SteamRemotestorage, FileWriteStreamClose);
    Createmethod(9, SteamRemotestorage, FileWriteStreamCancel);
    Createmethod(10, SteamRemotestorage, FileExists);
    Createmethod(11, SteamRemotestorage, FilePersisted);
    Createmethod(12, SteamRemotestorage, GetFileSize);
    Createmethod(13, SteamRemotestorage, GetFileTimestamp);
    Createmethod(14, SteamRemotestorage, GetSyncPlatforms);
    Createmethod(15, SteamRemotestorage, GetFileCount);
    Createmethod(16, SteamRemotestorage, GetFileNameAndSize);
    Createmethod(17, SteamRemotestorage, GetQuota);
    Createmethod(18, SteamRemotestorage, IsCloudEnabledForAccount);
    Createmethod(19, SteamRemotestorage, IsCloudEnabledForApp);
    Createmethod(20, SteamRemotestorage, SetCloudEnabledForApp);
    Createmethod(21, SteamRemotestorage, UGCDownload);
    Createmethod(22, SteamRemotestorage, GetUGCDownloadProgress);
    Createmethod(23, SteamRemotestorage, GetUGCDetails);
    Createmethod(24, SteamRemotestorage, UGCRead2);
    Createmethod(25, SteamRemotestorage, GetCachedUGCCount);
    Createmethod(26, SteamRemotestorage, GetCachedUGCHandle);
    Createmethod(27, SteamRemotestorage, PublishWorkshopFile1);
    Createmethod(28, SteamRemotestorage, CreatePublishedFileUpdateRequest);
    Createmethod(29, SteamRemotestorage, UpdatePublishedFileFile);
    Createmethod(30, SteamRemotestorage, UpdatePublishedFilePreviewFile);
    Createmethod(31, SteamRemotestorage, UpdatePublishedFileTitle);
    Createmethod(32, SteamRemotestorage, UpdatePublishedFileDescription);
    Createmethod(33, SteamRemotestorage, UpdatePublishedFileVisibility);
    Createmethod(34, SteamRemotestorage, UpdatePublishedFileTags);
    Createmethod(35, SteamRemotestorage, CommitPublishedFileUpdate);
    Createmethod(36, SteamRemotestorage, GetPublishedFileDetails1);
    Createmethod(37, SteamRemotestorage, DeletePublishedFile);
    Createmethod(38, SteamRemotestorage, EnumerateUserPublishedFiles);
    Createmethod(39, SteamRemotestorage, SubscribePublishedFile);
    Createmethod(40, SteamRemotestorage, EnumerateUserSubscribedFiles);
    Createmethod(41, SteamRemotestorage, UnsubscribePublishedFile);
    Createmethod(42, SteamRemotestorage, UpdatePublishedFileSetChangeDescription);
    Createmethod(43, SteamRemotestorage, GetPublishedItemVoteDetails);
    Createmethod(44, SteamRemotestorage, UpdateUserPublishedItemVote);
    Createmethod(45, SteamRemotestorage, GetUserPublishedItemVoteDetails);
    Createmethod(46, SteamRemotestorage, EnumerateUserSharedWorkshopFiles);
    Createmethod(47, SteamRemotestorage, PublishVideo1);
    Createmethod(48, SteamRemotestorage, SetUserPublishedFileAction);
    Createmethod(49, SteamRemotestorage, EnumeratePublishedFilesByUserAction);
    Createmethod(50, SteamRemotestorage, EnumeratePublishedWorkshopFiles);
    Createmethod(51, SteamRemotestorage, UGCDownloadToLocation);
};

struct Steamremotestorageloader
{
    Steamremotestorageloader()
    {
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage001", new SteamRemotestorage001);
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage002", new SteamRemotestorage002);
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage003", new SteamRemotestorage003);
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage004", new SteamRemotestorage004);
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage005", new SteamRemotestorage005);
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage006", new SteamRemotestorage006);
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage007", new SteamRemotestorage007);
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage008", new SteamRemotestorage008);
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage009", new SteamRemotestorage009);
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage010", new SteamRemotestorage010);
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage011", new SteamRemotestorage011);
        Interfacemanager::Addinterface(STEAM_REMOTESTORAGE, "SteamRemotestorage012", new SteamRemotestorage012);
    }
};
static Steamremotestorageloader Interfaceloader{};

#if !defined (_WIN32)
namespace { struct Createdir { Createdir() { mkdir(Storagedir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH); }; }; static Createdir Created{}; }
#else
namespace { struct Createdir { Createdir() { _mkdir(Storagedir); }; }; static Createdir Created{}; }
#endif
