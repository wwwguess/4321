// ROOM:__DIR__"canyon3"

inherit ROOM;
void create()
{
        set("short","����С·");
	set("long",@LONG                                   
��������ʯ����ƽ����С·�ϣ���᫵ĵ�·��������Ǳȱ���ƽ����
�ˣ����϶�ʮ��������չؿ��ˣ�����Ϊ��Ӫ������Ӫ����Ϊ��դ����Χ
�������������Ӫ���ƺ��ǲ�̫���ܡ�
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
        	"north" : __DIR__"canyon2",
        	"south" : __DIR__"canyon4",
	]) ); //eof(exits)
	
	setup();
	
	replace_program(ROOM);
} //EOF
