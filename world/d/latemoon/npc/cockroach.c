inherit NPC;

void create()
{
        set_name("�����", ({ "cockroach" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ�ǳ����ĵ���롣 \n");

        set("combat_exp",7000);
        set("score", 200);
        set("force", 200);
         set("max_force", 200);
        set_skill("dodge", 100);


        set("limbs", ({ "ͷ��", "����"}) );
         set("verbs", ({ "bite" }) );
        set_temp("armor", 50);

    set("chat_chance", 25);
    set("chat_msg", ({
	    (: this_object(), "random_move" :),
	    (: this_object(), "hide" :)
    }) );

        setup();
}

void hide()
{
	if( !environment() ) return;
	message("vision", "����������������ǽ�ߵ��ѷ��ˡ�\n", environment());
	call_out("disappear", 1);
}

void disappear()
{
	destruct(this_object());
}

