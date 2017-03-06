// boss.c

inherit NPC;

void create()
{
        set_name("Ǯ�ƹ�", ({ "boss qian", "qian", "boss" }) );
	set("nickname", "Ǯǧ��");
        set("long",
"Ǯ�ƹ񳤵���һ�������Ű㣬�װ����ֵģ���˵���Ѳ���֪����\n"
"�����䣬�ɱ����úܺá�һ˫С�۾��������Ƕ�����ϣ���ʱ��\n"
"�������ת�������ġ�̫�׾�¥�����Ǿ������ġ�\n"
	);

        set("age", 53);
        set("attitude", "peaceful");
        set("combat_exp", 1000);
        set("inquiry", ([
                "name": "������Ǯ���������ʲ������˽���Ǯǧ��\n",
                "̫�׾�¥": "������ǣ������ǵ�һ������\n",
		"����": "С���㡣͵͵�ظ����㣬����������ϵġ�\n",
		"����": "�Ƽ�û�У�������˲�����Ӧȥ�����ġ�\n"
        ]) );
        setup();
        add_money("gold", 1);
        carry_object("/obj/cloth")->wear();
}


void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
	        }
}

void greeting (object ob)
{
	if( !ob || environment(ob) != environment() ) 
		return;

	if (!ob->query("rank")) 
		say ("Ǯǧ��������ü��˵:�����ǿɲ���Ϊ���ǿ��ģ������˿��ߡ�\n");
	    else 
		say ("Ǯǧ�������Ц������ȥ������������ӭ���ˡ�\n");
}

