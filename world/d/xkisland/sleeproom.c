// sleep_room: /u/dan/room sleeproom.c
//dan

inherit ROOM;

void create()
{
    set("short", "��Ϣ��");
    set("long", @LONG
ǧ��Ŷ�,�Ĵ������������.�ı��Ѿ��߲߰���,��ϡ�ɼ���
Щ�Ѻ���.ǽ���������Ͳʻ���һЩ�ֻ�.��������Ϣ��.ǽ��
��д���붴��֪�����붴��������ѧ���о������ơ�
                  �мǣ������߻���ħ.
                                  ------����������
LONG
    );  
    
    set("exits", ([ /* sizeof() == 1 */
      "west" : __DIR__"cave.c",
      
    ]));
    set("sleep_room",1);  
    set("no_fight",1);
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
