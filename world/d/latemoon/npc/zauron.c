inherit NPC;
#include <ansi.h>
 

void create()
{
        set_name("����", ({ "zauron","zau","ron" }) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", @TEXT
������ʮ��Ư���������̲�ס���������ۣ���������
���ŵ���������������������ò�������ͷ�����ŵ�
��������ӯ�Ĳ���������Ŷ!
TEXT
);
       set("class", "dancer");
       set("combat_exp", 200000);
        set_skill("unarmed",70);
        set_skill("dodge", 80);
        set_skill("force",70);
        set_skill("sword",70);
        set_skill("stormdance", 50);
        map_skill("dodge","stormdance");
        set("force", 3000);
        set("max_force", 600);

        set("force_factor", 10);
        set("inquiry", ([
        "��" : "�������Ĳ���!�ұȽ�ϲ����̬�Ļ��\n",
        "���" : "��˵��̰�汻���ڽ����ҡ��������������! \n",
        ]));
        create_family("����ׯ",2,"����");

        setup();
        carry_object("/d/latemoon/obj/clasp")->wear();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/skirt2")->wear();
        carry_object("/d/latemoon/obj/bamboo_sword")->wield();

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
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        switch( random(2) ) {
                case 0:
                  say( "���ض���΢Ц�����ƵĶ�����ͷ��\n");
                        break;
                case 1:
                  say( "���ض���΢Ц������ϸ��������� \n ˵������λ" +
RANK_D->query_respect(ob)
                   + "����ã���ӭ��������ׯ��\n");
        }
}

