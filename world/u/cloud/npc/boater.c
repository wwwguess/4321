// boater.c

inherit NPC;

string	cross_river();

void create()
{
        set_name("����", ({ "boater" }) );
        set("title", "�ɿ�");
        set("gender", "����" );
        set("age", 30);
        set("long", "�����Ƥ��ɹ����ڣ����ϵĲ�ɣ�Ƕ���ڶɵĺۼ���\n");
	set("str", 27);
        set("combat_exp", 1500);
        set("attitude", "heroism");
        set_skill("unarmed", 100);
        set_skill("parry", 50);
        set_skill("dodge", 30);

        set("inquiry", ([
		"����" : (: cross_river :),
		"�ڶ�" : (: cross_river :), 
        ]) );

	setup();
	add_money("coin", 200);
        carry_object("/obj/cloth")->wear();
}

int accept_object(object who, object ob)
{
        if( !who->query("marks/����") ) {
                if( ob->value() >= 2 ) {
			command("nod");
			message("vision", "����˵���͹ٿ��Թ�������\n",
                                 who );
	                message("vision", "����������С������������ȥ��\n",
                        	 who );
                        who->set("marks/����", 1);
                        return 1;
                } else {
                        say("��ô�٣��һ�Ҫ����ѽ��\n");
                        return 0;
                }
        } else{
                say("��л��λ"+RANK_D->query_respect(ob)+"��\n");
		who->set("marks/����", 0);
	}
        return 1;
}

string	cross_river()
{
	return "����������";
}

