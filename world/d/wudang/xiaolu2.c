// xiaolu2.c �ּ�С��

#include <room.h>
inherit ROOM;
int valid_leave();
void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ����������ƺ���һ����ª��СԺ��
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiaoyuan.c",
                "south" : __DIR__"xiaolu1",
        ]));

        create_door("north", "����", "south", DOOR_CLOSED);

        set("objects",([
                CLASS_D("wudang") + "/yin" : 1,
        ]));

        setup();
 }

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");
      if (objectp(present("yin liting", environment(me))) && dir == "north")
       {
        if ((!myfam || myfam["family_name"] != "�䵱��"))
           return notify_fail("����ͤ��סȥ·,��ȭ������ʦ�����ڱչأ�û�²��ô��š�\n");
        if ((int)me->query_skill("taiji-shengong", 1) < 80) 
           return notify_fail("����ͤ����һ��,Ȱ��������ûҪ������,��Ҫ����ʦ�������˼����ޡ�\n");
       }         
        return ::valid_leave(me, dir);
}
