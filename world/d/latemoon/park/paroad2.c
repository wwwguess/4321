inherit ROOM;
#include <ansi.h>

string look_sign(object me);

void create()
{
   set("short", "�����");
	set("long", @LONG
ת�������ţ�����¶��һ���������Ͱ�ǽ��ǽͷ�õ����ڻ���
�м������ӻ����������ϼһ�㣬�������é�ݣ�����ȴ��ɣ��
�ܡ��ȡ�ɼ��ɫ��ľ�������������۱���������飬������һ��  
��������һʯ��(sign)���Ա���һЩ���߲˻���
LONG
	);
    set("item_desc", ([
        "sign": (: look_sign :)
    ]) );
	set("exits", ([ /* sizeof() == 2 */
       "east" :__DIR__"bridge2",
       "northwest" :__DIR__"moon3",

]));

    set("objects", ([
        __DIR__"npc/rabbit" : 2 ]) );
	setup();
}

string look_sign(object me)
{
    if( wizardp(me) )
        return "����һ��������ʾ����ʱδ���š�\n";
    else
        return "\n �����񡹡����Ĺ��������项 \n\n" +
            HIM "         ��â������\n" +
                "         ��������ɽ\n\n" NOR ;
}
