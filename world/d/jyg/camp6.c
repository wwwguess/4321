// ROOM:__DIR__"camp6"
// by solor (98.2.21)

inherit ROOM;
void create()
{
        set("short","ƫ��Ӫ��");
	set("long",@LONG                                   
������ƫ����Ӫ�ʣ�����������ƹ�һ����������졣
�򶫱��Ǹ���Ӫ�ʣ���û�о����������ǲ���
����ġ�
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/pianjiang" : 1,
		__DIR__"npc/qipaiguan" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
