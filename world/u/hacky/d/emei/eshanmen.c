// Room: /d/emei/shanmen.c ������ ɽ��


#include <room.h>
inherit ROOM;

void create()
{
    set("short", "ɽ��");
    set("long", @LONG
һ���޴���Ʒ��������Ƭɽ��֮�䣬�Ʒ����Ϸ���������
������֣������ҡ����ּ���Щ���䣬����ȥ�����Զ����λ
��ʮ�����ɮ���ֳֽ䵶����ɽ�����ࡣ�������һ��ʯ����
LONG
    );

    set("exits", ([
	"northeast" : __DIR__"shijie8",
        "west" : __DIR__"baoguosi",
    ]));

    set("outdoors", "emei");
    set("objects",([
        CLASS_D("shaolin") + "/xu-tong" : 1,
        CLASS_D("shaolin") + "/xu-ming" : 1,
    ]));
    setup();
    replace_program(ROOM);
}
/*
int valid_leave(object me, string dir)
{
    object *inv;
    mapping myfam, mygen;
    int i;

    if (me->query("gender") == "����" && dir == "west" ) {
        if(objectp(present("xu tong", environment(me))))
            return notify_fail("��ͨ������ס�����һ��˵����ǧ����������������"
                "��" + RANK_D->query_respect(me) +"\n����ɽȥ�ɣ����"
                "����ûȤ��\n");
        else if(objectp(present("xu ming", environment(me))))
            return notify_fail("����������������ǰ��˫�ֺ�ʲ˵���������ӷ�"
                "��λ" + RANK_D->query_respect(me) + "��������\nˡС�²��Ӵ�Ů"
                "�͡�Ůʩ������һ����𣬺η�ȥ��üɽ��ϲ��\n");
    }

    myfam = (mapping)me->query("family");

    if ((!myfam || myfam["family_name"] != "������" ) && dir == "eastup") {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("xu tong", environment(me))))
                    return notify_fail("��ͨ��ס��˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�����ǧ���"
                        "��أ����\n���óֱ�����ɽ��\n");
                else if(objectp(present("xu ming", environment(me))))
                    return notify_fail("����������������ǰ��˫�ֺ�ʲ˵������"
                        "���ӷ���λ" + RANK_D->query_respect(me) + "������"
                        "\n���С������徲֮�أ����������赶Ū��������ʩ����"
                        "�¡�\n");
    }
    return ::valid_leave(me, dir);
}
*/
