// ROOM:__DIR__"camp4"

inherit ROOM;
void create()
{
        set("short","�ر�Ӫ��");
	set("long",@LONG                                   
������һ��Ⱥ���ر�����֪��������ʲô��Ӫ��������һ�����ӣ���
������˸�ʽ�����Ķľߣ�С��ʣ��Ͳ�ˮ��
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp1",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/xinbing" : 2,
		__DIR__"npc/laobing" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
