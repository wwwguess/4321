// laozhe.c
//by yuer

inherit NPC;
int ask_me();


void create()
{
	set_name("����", ({ "lao zhe", "lao" }));
	set("long", "��λ����������ɣ�����Ƴ������ⱼ������Ȼ��λ����ʶ������ˡ�\n");
	set("gender", "����");
	set("age", 65);

	set_skill("fanwen", 200);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 20);

	set("combat_exp", 200000);
	set("shen_type", 1);
 set("inquiry", ([
                "�ֻ�" : (: ask_me :),
                "picture" : (: ask_me :),

               ]) );
	setup();

}
int ask_me()
{
        if ( this_player()->query_temp("marks/��") ) {
            say("����˵�����㻹����û��? �ʻ���ҪǮ��?\n");
	return 0;
        }
        else {
                say(
"�⻭���Ҵ�����һ���ط��������ġ�\n"
" ���ϵ���ֻ������ʶ����Ҫ��ѧ���͵ø���ʮ�����ӡ�\n"
                );
                this_player()->set_temp("marks/��", 1);
        }
        return 1;
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/��"))  return 0; 
	return 1;
}

int accept_learn(object me, string skill)
{
	if (skill=="fanwen")
	{
		if (!(int)me->query_temp("mark/��"))
			return 0; 
		me->add_temp("mark/��", -1);
		return 1;
	}

	return 0;
}


int accept_object(object who, object ob)
{
	            if (!(int)who->query_temp("mark/��"))
		who->set_temp("mark/��", 0);
	   if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("����ͬ��ָ��$NһЩ�������ĵ����⡣\n", who);
		who->add_temp("mark/��", ob->value() / 50);
		return 1;
                       	}

	return 0;
}

