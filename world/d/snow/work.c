// work.c
//#include "/feature/damage.c"

inherit ROOM;

void create()
{
        set("short", "����ӹ���");
        set("long", @LONG
����һ�����ӹ����������ǹ����ѿǳ��׵ĵط����׳��ϰ���һ��һ
����֪����ʮ�־����ĸ��ݵ������ˣ����Ǵ���һ����Ц������Կ���
���������ææµµ�Ĺ����ţ��ſڹ���һ������(sign)��������ͨ��
ѩͤ���ֵĴ��š�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/snow/mstreet2",
]));

        set("item_desc", ([
                "sign": @TEXT
��������ȱ���֣������Ӷһ���̹����ɻ

work     ��ʼ������

TEXT
        ]) );
    set("no_fight", 1);
    set("no_magic", 1);
        setup();
}

void init()
{
        add_action("do_work", "work");
}

int do_work(string arg)
{
        object ob;
        object me;
	int i;
        me = this_player();

message_vision("$N����Ĺ������ڽ����ˣ�����Ҳ�۵�Ҫ��\n", 
me);
me->add("gin",-30);
me->add("sen",-30);
//receive_damage("gin",30,me);
//receive_damage("sen",30, me);
for(i=1;i<4;i++)
{
ob = new("/obj/money/silver");
ob->move(me);
}
message_vision("�ϰ��$N˵��������Ĺ�Ǯ��\n", me);
}
