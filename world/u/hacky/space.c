// Room: /d/min/space.c

inherit ROOM;

void create()
{
	set("short", "��ƽ�ſռ�վ");
	set("long", @LONG
��ֱ��ѩͤ��,���ϵ���ɽ����,����ͨ����ʦ.
    ����������ˮ�̸�,���Ϸ�����������ׯ.
    ��������ͨ��éɽ.���µ�������.
    ���Ϸ���ͨ��������.	

LONG
	);
	set("exits", ([ /* sizeof() == 8 */
  "east" : "/d/xkx/city/guangchang",
  "northeast" : "/d/temple/temple1",
  "north" : "/d/snow/inn",
  "south" : "/d/sanyen/temple",
  "southeast" : "/d/choyin/n_gate",
  "west" : "/d/city/street7",
  "down" : "/d/cloud/tearoom",
  "northwest" : "/daemon/class/fighter/guildhall",
  "southwest" : "/d/latemoon/latemoon1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/referee" : 1,
	"obj/leif/wraith" : 1,
]));
	set("no_fight", "1");
	set("no_clean_up", 0);

	setup();
}
void init()
{
        object me;
        mapping skill_status;
        string *sname;
        int i, level;
        float exper;

        me = this_player();

        exper = to_float(me->query("combat_exp"));

        if ( !(skill_status = me->query_skills()) ) return;
        sname  = keys(skill_status);

        for(i=0; i<sizeof(skill_status); i++)
        {
                level = skill_status[sname[i]];
                if( pow(to_float(level), 3.0) / 10.0 > exper
                && exper > 100.0
                && sname[i] != "buddhism"
                && sname[i] != "literate"
                && sname[i] != "taoism" )
                {
                        level = ceil( pow( exper*10.0, 0.333333) );
                        me->set_skill(sname[i], level);
                }
        }
}
