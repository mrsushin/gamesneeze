static void DrawBox( ImColor color, int x, int y, int w, int h, C_BaseEntity* entity ) {
	if ( Settings::ESP::Boxes::type == BoxType::FRAME_2D ) 
  {
		int VertLine = w / 3;
		int HorzLine = h / 3;
		int squareLine = std::min( VertLine, HorzLine );

		// top-left corner / color
		Draw::AddRect( x, y, x + squareLine, y + 1, color );
		Draw::AddRect( x, y, x + 1, y + squareLine, color );



		// top-left corner / missing edges
		Draw::AddRect( x + squareLine, y - 1, x + squareLine + 1, y + 2, ImColor( 10, 10, 10, 190 ) );
		Draw::AddRect( x - 1, y + squareLine, x + 2, y + squareLine + 1, ImColor( 10, 10, 10, 190 ) );


		// top-right corner / color
		Draw::AddRect( x + w - squareLine, y, x + w, y + 1, color );
		Draw::AddRect( x + w - 1, y, x + w, y + squareLine, color );



		// top-right corner / missing edges
		Draw::AddRect( x + w - squareLine - 1, y - 1, x + w - squareLine, y + 2, ImColor( 10, 10, 10, 190 ) );
		Draw::AddRect( x + w - 2, y + squareLine, x + w + 1, y + squareLine + 1, ImColor( 10, 10, 10, 190 ) );


		// bottom-left corner / color
		Draw::AddRect( x, y + h - 1, x + squareLine, y + h, color );
		Draw::AddRect( x, y + h - squareLine, x + 1, y + h, color );



		// bottom-left corner / missing edges
		Draw::AddRect( x + squareLine, y + h - 2, x + squareLine + 1, y + h + 1, ImColor( 10, 10, 10, 190 ) );
		Draw::AddRect( x - 1, y + h - squareLine - 1, x + 2, y + h - squareLine, ImColor( 10, 10, 10, 190 ) );


		// bottom-right corner / color
		Draw::AddRect( x + w - squareLine, y + h - 1, x + w, y + h, color );
		Draw::AddRect( x + w - 1, y + h - squareLine, x + w, y + h, color );


		// bottom-right corner / missing edges
		Draw::AddRect( x + w - squareLine, y + h - 2, x + w - squareLine + 1, y + h + 1, ImColor( 10, 10, 10, 190 ) );
		Draw::AddRect( x + w - 2, y + h - squareLine - 1, x + w + 1, y + h - squareLine, ImColor( 10, 10, 10, 190 ) );
