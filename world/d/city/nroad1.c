#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
��������һ����ʯ�̵صĴ�����ϣ��������������������ӵ�
���������Ŵ󳵵���򣬸�������ľ��ˣ������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ��ɧ������·���Ը�
��һƬС���֣��ϱ߾��Ǿ�ʦ��
LONG
        );

        set("exits", ([
                "north"          : "/d/city/nroad2",
                "enter"          : "/d/city/northdoor" ]) );

        set("outdoors", "city"); 
        create_door("enter", "����", "out" );
        setup();
        replace_program(ROOM); 
}
void init()
{
	add_action("do_yell","yell");
}
void do_yell()
{
	if(!query("exit/up")) 
	   set("exits/up",__DIR__"room");
}
